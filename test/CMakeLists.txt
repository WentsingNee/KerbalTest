
include(${CMAKE_SOURCE_DIR}/cmake/add_kerbal_parent_target.cmake)


if (${KERBAL_WASM})
    if (NOT DEFINED WASM_RUN_UTEST_INVOKER)
        set (WASM_RUN_UTEST_INVOKER "node")
    endif ()
    set (run_utest_invoker "${WASM_RUN_UTEST_INVOKER}")
endif ()


function(add_kerbal_utest_target_impl target target_src_file)
    add_executable(${target} ${target_src_file})
    add_kerbal_parent_target(${target})
    set_target_properties(${target}
            PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/targets
    )
    target_include_directories(${target} PUBLIC "${PROJECT_SOURCE_DIR}/include")
    if (KERBAL_TEST_USE_LIBCXX)
        target_compile_options(${target} PUBLIC -stdlib=libc++)
        target_link_libraries(${target} PUBLIC ${LIB_CPP})
        target_link_libraries(${target} PUBLIC ${LIB_CPPABI})
    endif ()
    if (KERBAL_TEST_ENABLE_SANITIZE)
        target_compile_options(${target} PUBLIC -fsanitize=address)
        target_compile_options(${target} PUBLIC -fsanitize=undefined)
        target_link_libraries(${target} PUBLIC ${LIB_ASAN})
        target_link_libraries(${target} PUBLIC ${LIB_UBSAN})
    endif ()
    if (KERBAL_TEST_ENABLE_GCOV)
        target_compile_options(${target} PUBLIC --coverage)
        target_link_options(${target} PUBLIC --coverage)
    endif ()
    if (KERBAL_WASM)
        target_compile_options(${target} PUBLIC -fexceptions)
        target_link_options(${target} PUBLIC -fexceptions)
        set_target_properties(${target}
                PROPERTIES RUNTIME_OUTPUT_NAME ${target}.html
        )
    endif ()
    add_test(
            NAME ${target}
            COMMAND ${target}
    )

    # run_utest_target
    get_target_property(path ${target} RUNTIME_OUTPUT_DIRECTORY)
    if (${CMAKE_GENERATOR} MATCHES "Visual Studio")
        file(RELATIVE_PATH path ${PROJECT_BINARY_DIR} "${path}/$<CONFIG>/${target}")
    else()
        file(RELATIVE_PATH path ${PROJECT_BINARY_DIR} "${path}/${target}")
    endif ()
    if (${CMAKE_CXX_PLATFORM_ID} MATCHES "Windows")
        set(path "./${path}.exe")
    else ()
        set(path "./${path}")
    endif ()

    set(run_utest_target_name "run_${target}")
    if (${CMAKE_CXX_PLATFORM_ID} MATCHES "Windows")
        add_custom_target(${run_utest_target_name}
                COMMAND if not exist test_output mkdir test_output
                COMMAND ${path} > test_output/${target}.out.txt
                COMMAND type test_output\\${target}.out.txt
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                COMMENT "Running utest target ${target}"
        )
    else ()
        add_custom_target(${run_utest_target_name}
                COMMAND
                    mkdir -p test_output\;
                    ${run_utest_invoker} ${path} | tee test_output/${target}.out.txt\;
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                COMMENT "Running utest target ${target}"
        )
    endif ()
    add_dependencies(${run_utest_target_name} ${target})
    add_kerbal_parent_target(${run_utest_target_name})
endfunction()

macro(add_kerbal_utest_target target target_src_file)
    add_kerbal_utest_target_impl(${target} ${target_src_file})
    list(APPEND utest_targets ${target})
endmacro()


function(add_kerbal_utest_target_wih_ie target target_src_file ie)
    if (NOT KERBAL_TEST_SUPPORT_${ie})
        message(WARNING "Compiler doesn't support ${ie}")
        return()
    endif ()
    set(target_name_with_ie ${target}_${ie})
    add_kerbal_utest_target(${target_name_with_ie} ${target_src_file})
    target_compile_options(${target_name_with_ie} PUBLIC ${KERBAL_TEST_FLAGS_${ie}})
endfunction()


file(GLOB_RECURSE test_src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (file ${test_src_files})
    if (NOT file MATCHES "(.+)\\.test\\.cpp$")
        string(APPEND ignored_utest_src_files "${CMAKE_CURRENT_SOURCE_DIR}/${file}:0\n")
        continue()
    endif ()
    string(REPLACE "/" "." target ${CMAKE_MATCH_1})
    string(PREPEND target "utest.")
    message(VERBOSE "	add: ${target}  <=  ${CMAKE_CURRENT_SOURCE_DIR}/${file}")
    add_kerbal_utest_target(${target} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    if (${KERBAL_TEST_ENABLE_PRECOMPILE_HEADER})
        target_precompile_headers(${target} REUSE_FROM kerbal_test_precompile_header)
    endif ()
    set(utest_targets ${utest_targets} PARENT_SCOPE)
endforeach ()

message("\n")

if (NOT ignored_utest_src_files STREQUAL "")
    message(WARNING "These files have been ignored:")
    message(STATUS "${ignored_utest_src_files}")
endif ()


file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (child ${children})
    if (IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${child}" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${child}/CMakeLists.txt")
        message("child  ${child}")
        add_subdirectory(${child})
    endif ()
endforeach()


set(utest_targets_count 0)
foreach (target ${utest_targets})
    message(VERBOSE "utest-target ${utest_targets_count}: ${target}")
    math(EXPR utest_targets_count "${utest_targets_count} + 1")
endforeach ()
message("utest targets: ${utest_targets_count}")
message("\n")


# ctest
enable_testing()
