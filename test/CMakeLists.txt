
include(${PROJECT_SOURCE_DIR}/cmake/add_kerbal_parent_target.cmake)


if (KERBAL_WASM)
    if (NOT DEFINED KTEST_WASM_RUN_UTEST_INVOKER)
        message(STATUS "Finding node")
        find_program(KTEST_WASM_RUN_UTEST_INVOKER "node" REQUIRED)
        message(STATUS "Found node: ${KTEST_WASM_RUN_UTEST_INVOKER}")
    endif ()
endif ()


if (NOT DEFINED KTEST_RUN_UTEST_INVOKER)
    if (KERBAL_WASM)
        if (NOT DEFINED KTEST_WASM_RUN_UTEST_INVOKER)
            message(FATAL_ERROR "Neither KTEST_RUN_UTEST_INVOKER nor KTEST_WASM_RUN_UTEST_INVOKER is defined")
        endif ()
        set(KTEST_RUN_UTEST_INVOKER "${KTEST_WASM_RUN_UTEST_INVOKER}")
    endif ()
endif ()


add_custom_target(
        run_utest_make_test_output_dir
        COMMAND ${CMAKE_COMMAND} -E make_directory test_output
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)


function(add_ktest_utest_target target target_src_file)
    add_executable(${target} ${target_src_file})
    set_target_properties(${target}
            PROPERTIES ktest_category "utest"
    )
    add_kerbal_parent_target(${target})
    set_property(
            GLOBAL
            APPEND
            PROPERTY KTEST_UTEST_TARGETS_MANIFEST "${target}"
    )
    ktest_basic_configuration(${target})
    set_target_properties(${target}
            PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/targets
    )
    if (KERBAL_WASM)
        set_target_properties(${target}
                PROPERTIES RUNTIME_OUTPUT_NAME ${target}.js
        )
    endif ()
    add_test(
            NAME ${target}
            COMMAND ${target}
    )

    # run_utest_target
    get_target_property(path ${target} RUNTIME_OUTPUT_DIRECTORY)
    if (NOT path)
        set(path "${CMAKE_CURRENT_BINARY_DIR}")
    endif ()
    get_target_property(target_output_name ${target} RUNTIME_OUTPUT_NAME)
    if (NOT target_output_name)
        set(target_output_name "${target}${CMAKE_EXECUTABLE_SUFFIX}")
    endif ()
    if (CMAKE_GENERATOR MATCHES "Visual Studio")
        file(RELATIVE_PATH path ${PROJECT_BINARY_DIR} "${path}/$<CONFIG>/${target_output_name}")
    else()
        file(RELATIVE_PATH path ${PROJECT_BINARY_DIR} "${path}/${target_output_name}")
    endif ()

    if ((DEFINED KTEST_CI) AND (NOT KTEST_CI STREQUAL ""))
        list(APPEND run_utest_args "--run_in_ci")
    endif ()

    set(run_utest_args_with_escape "")
    foreach (arg IN LISTS run_utest_args)
        set(run_utest_args_with_escape "${run_utest_args_with_escape}${arg}\;")
    endforeach ()

    foreach (run_modified IN ITEMS True False)
        if (run_modified)
            set(run_utest_target_name "runm_${target}")
            set(hash_file "${PROJECT_BINARY_DIR}/runm_utest_hash/${target}")
            set(ktest_category "runm_utest")
        else ()
            set(run_utest_target_name "run_${target}")
            set(hash_file "")
            set(ktest_category "run_utest")
        endif ()

        add_custom_target(
                ${run_utest_target_name}
                COMMAND
                    "${CMAKE_COMMAND}"
                    -DCMAKE_MODULE_PATH="${CMAKE_MODULE_PATH}"
                    -DKTEST_RUN_UTEST_INVOKER="${KTEST_RUN_UTEST_INVOKER}"
                    -DTARGET="${target}"
                    -DPATH="${path}"
                    -DHASH_FILE="${hash_file}"
                    -DRUN_UTEST_ARGS="${run_utest_args_with_escape}"
                    -DPROJECT_BINARY_DIR="${PROJECT_BINARY_DIR}"
                    -P "${PROJECT_SOURCE_DIR}/cmake/run_utest.cmake"
                WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
                DEPENDS ${target} run_utest_make_test_output_dir
        )
        set_target_properties("${run_utest_target_name}"
                PROPERTIES ktest_category "${ktest_category}"
        )

        if (KTEST_ENABLE_SANITIZE AND CMAKE_CXX_COMPILER MATCHES "MSVC")
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
    endforeach ()
endfunction()


function(add_ktest_utest_target_wih_ie target target_src_file ie)
    if (NOT KERBAL_SUPPORT_${ie})
        message(WARNING "Compiler doesn't support ${ie}")
        return()
    endif ()
    add_ktest_utest_target(${target} ${target_src_file})
    kerbal_target_with_ies(
            TARGET ${target}
            IEs ${ie}
            SCOPE PUBLIC
            MODE REQUIRED
    )
endfunction()


file(GLOB_RECURSE test_src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (file IN LISTS test_src_files)
    if (NOT file MATCHES "(.+)\\.test\\.cpp$")
        string(APPEND ignored_utest_src_files "${CMAKE_CURRENT_SOURCE_DIR}/${file}:0\n")
        continue()
    endif ()
    string(REPLACE "/" "." target ${CMAKE_MATCH_1})
    string(PREPEND target "utest.")
    message(VERBOSE "	add: ${target}  <=  ${CMAKE_CURRENT_SOURCE_DIR}/${file}")
    add_ktest_utest_target(${target} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    if (KTEST_ENABLE_PRECOMPILE_HEADER)
        target_precompile_headers(${target} REUSE_FROM ktest_precompile_header)
    endif ()
endforeach ()

message("\n")

if (NOT ignored_utest_src_files STREQUAL "")
    message(WARNING "These files have been ignored:")
    message(STATUS "${ignored_utest_src_files}")
endif ()


file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (child IN LISTS children)
    if (IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${child}" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${child}/CMakeLists.txt")
        message("child  ${child}")
        add_subdirectory(${child})
    endif ()
endforeach()


set(utest_targets_count 0)
get_property(
        ktest_utest_targets_manifest
        GLOBAL
        PROPERTY KTEST_UTEST_TARGETS_MANIFEST
)
foreach (target IN LISTS ktest_utest_targets_manifest)
    message(VERBOSE "utest-target ${utest_targets_count}: ${target}")
    math(EXPR utest_targets_count "${utest_targets_count} + 1")
endforeach ()
message("utest targets: ${utest_targets_count}")
message("\n")
