
include(${PROJECT_SOURCE_DIR}/cmake/add_kerbal_parent_target.cmake)


if (${KERBAL_WASM})
    if (NOT DEFINED KTEST_WASM_RUN_UTEST_INVOKER)
        message(STATUS "Finding node")
        find_program(KTEST_WASM_RUN_UTEST_INVOKER "node" REQUIRED)
        message(STATUS "Found node: ${KTEST_WASM_RUN_UTEST_INVOKER}")
    endif ()
endif ()


if (NOT DEFINED KTEST_RUN_UTEST_INVOKER)
    if (${KERBAL_WASM})
        if (NOT DEFINED KTEST_WASM_RUN_UTEST_INVOKER)
            message(FATAL_ERROR "Neither KTEST_RUN_UTEST_INVOKER nor KTEST_WASM_RUN_UTEST_INVOKER is defined")
        endif ()
        set (KTEST_RUN_UTEST_INVOKER "${KTEST_WASM_RUN_UTEST_INVOKER}")
    endif ()
endif ()


add_custom_target(
        run_utest_make_test_output_dir
        COMMAND ${CMAKE_COMMAND} -E make_directory test_output
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)


function(add_ktest_utest_target_impl target target_src_file)
    add_executable("${target}" ${target_src_file})
    add_kerbal_parent_target(${target})
    set_target_properties(${target}
            PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/targets
    )
    target_link_libraries(${target} PUBLIC Kerbal::kerbal)
    target_include_directories(${target} PUBLIC "${PROJECT_SOURCE_DIR}/include")
    if (KTEST_USE_LIBCXX)
        target_compile_options(${target} PUBLIC -stdlib=libc++)
        target_link_libraries(${target} PUBLIC ${KTEST_LIB_CPP})
        target_link_libraries(${target} PUBLIC ${KTEST_LIB_CPPABI})
    endif ()
    if (KTEST_ENABLE_SANITIZE)
        if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
            target_compile_options(${target} PUBLIC /fsanitize=address)
        else ()
            target_compile_options(${target} PUBLIC -fsanitize=address)
            target_compile_options(${target} PUBLIC -fsanitize=undefined)
            target_link_libraries(${target} PUBLIC ${KTEST_LIB_ASAN})
            target_link_libraries(${target} PUBLIC ${KTEST_LIB_UBSAN})
        endif ()
    endif ()
    if (KTEST_ENABLE_GCOV)
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

    if (NOT ${KTEST_CI} STREQUAL "")
        set (run_utest_args "--run_in_ci")
    endif ()

    set(run_utest_target_name "run_${target}")
    add_custom_target(${run_utest_target_name}
            COMMAND ${KTEST_RUN_UTEST_INVOKER} ${path} ${run_utest_args} > test_output/${target}.out.txt
            COMMAND ${CMAKE_COMMAND} -E cat test_output/${target}.out.txt
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            COMMENT "Running utest target ${target}"
            DEPENDS ${target} run_utest_make_test_output_dir
    )

    if (${KTEST_ENABLE_SANITIZE} AND ${CMAKE_CXX_COMPILER} MATCHES "MSVC")
        if (NOT TARGET copy_sanitize_dll_before_run_utest)
            add_custom_target(
                    copy_sanitize_dll_before_run_utest
                    COMMAND ${CMAKE_COMMAND} -E copy ${KTEST_LIB_ASAN_DLL} ${PROJECT_BINARY_DIR}/targets
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            )
        endif ()
        add_dependencies(${run_utest_target_name} copy_sanitize_dll_before_run_utest)
    endif ()

    add_kerbal_parent_target(${run_utest_target_name})
endfunction()

macro(add_ktest_utest_target target target_src_file)
    add_ktest_utest_target_impl(${target} ${target_src_file})
    list(APPEND utest_targets ${target})
endmacro()


function(add_ktest_utest_target_wih_ie target target_src_file ie)
    if (NOT KTEST_SUPPORT_${ie})
        message(WARNING "Compiler doesn't support ${ie}")
        return()
    endif ()
    add_ktest_utest_target(${target} ${target_src_file})
    target_compile_options(${target} PUBLIC ${KTEST_FLAGS_${ie}})
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
    add_ktest_utest_target(${target} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    if (${KTEST_ENABLE_PRECOMPILE_HEADER})
        target_precompile_headers(${target} REUSE_FROM ktest_precompile_header)
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
