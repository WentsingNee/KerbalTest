

macro(add_kerbal_test_target target target_src_file)
    add_executable(${target} ${target_src_file})
    set_target_properties(${target}
            PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/targets
    )
    target_include_directories(${target} PUBLIC ./)
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
    if (KERBAL_TEST_GCOV)
        target_compile_options(${target} PUBLIC --coverage)
        target_link_options(${target} PUBLIC --coverage)
    endif ()
    add_test(
            NAME ${target}
            COMMAND ${target}
    )
    set(test_targets ${test_targets} ${target})
endmacro()


macro(add_kerbal_test_target_wih_ie target target_src_file ie)
    if (${KERBAL_TEST_SUPPORT_${ie}})
        set(target_name_with_ie ${target}.${ie})
        add_kerbal_test_target(${target_name_with_ie} ${target_src_file})
        target_compile_options(${target_name_with_ie} PUBLIC ${KERBAL_TEST_FLAG_${ie}})
    else ()
        message(WARNING "Compiler doesn't support ${ie}")
    endif ()
endmacro()


file(GLOB_RECURSE test_src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (file ${test_src_files})
    string(REGEX MATCH "(.+)\\.test\\.cpp$" _ ${file})
    if (CMAKE_MATCH_1)
        string(REPLACE "/" "." target ${CMAKE_MATCH_1})
        string(PREPEND target "test.")
        message("	add: ${target}  <=  ${CMAKE_CURRENT_SOURCE_DIR}/${file}")
        add_kerbal_test_target(${target} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        set(test_targets ${test_targets} PARENT_SCOPE)
    else ()
        message(WARNING "   ${file} has been ignored")
    endif ()
endforeach ()

message("\n")


file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (child ${children})
    if (IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${child}" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${child}/CMakeLists.txt")
        message("child  ${child}")
        add_subdirectory(${child})
    endif ()
endforeach()


set(test_targets_count 0)
foreach (target ${test_targets})
    message("test-target ${test_targets_count}: ${target}")
    math(EXPR test_targets_count "${test_targets_count} + 1")
endforeach ()
message("test targets: ${test_targets_count}")
message("\n")


# ctest
enable_testing()


foreach (target ${test_targets})
    set(run_target_name "run_${target}")
    get_target_property(path ${target} RUNTIME_OUTPUT_DIRECTORY)
    if (${CMAKE_GENERATOR} MATCHES "Visual Studio")
        file(RELATIVE_PATH path ${PROJECT_BINARY_DIR} ${path}/$<CONFIG>/${target})
    else()
        file(RELATIVE_PATH path ${PROJECT_BINARY_DIR} ${path}/${target})
    endif ()
    if (${CMAKE_CXX_PLATFORM_ID} MATCHES "Windows")
        add_custom_target(${run_target_name}
                COMMAND if not exist test_output mkdir test_output
                COMMAND ./${path}.exe > test_output/${target}.out.txt
                COMMAND cat test_output/${target}.out.txt
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                COMMENT "Running test target ${target}"
        )
    else ()
        add_custom_target(${run_target_name}
                COMMAND
                    mkdir -p test_output\;
                    ./${path} > test_output/${target}.out.txt\;
                    cat test_output/${target}.out.txt
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                COMMENT "Running test target ${target}"
        )
    endif ()
    list(APPEND run_test_targets_list ${run_target_name})
endforeach ()


add_custom_target(run_test_targets
        DEPENDS ${run_test_targets_list}
)
