#
# @file       run_utest.cmake
# @brief
# @date       2024-04-01
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

cmake_minimum_required(VERSION 3.10)

include(Kerbal/list_ext)


##
# CACHED_HASH_FILE_PATH one, optional
# RUN_UTEST_ARGS  multi
function(run_utest target path)
    kerbal_sublist("${ARGV}" 2 -1 ARGV)
    cmake_parse_arguments(
            ""
            ""
            "CACHED_HASH_FILE_PATH"
            "RUN_UTEST_ARGS"
            ${ARGV}
    )

    set(cached_hash_file_path ${_CACHED_HASH_FILE_PATH})
    set(run_utest_args ${_RUN_UTEST_ARGS})

    if (DEFINED cached_hash_file_path)
        execute_process(
                COMMAND
                    ${CMAKE_COMMAND} -E sha512sum ${path}
                OUTPUT_VARIABLE binary_hash
        )
        message(STATUS "binary_hash: ${binary_hash}")
        if (EXISTS "${cached_hash_file_path}")
            file(READ "${cached_hash_file_path}" cached_hash)
            message(STATUS "cached_hash: ${cached_hash}")
            if (cached_hash STREQUAL binary_hash)
                message(STATUS "target: ${target} is skipped because it has run")
                return()
            endif ()
        endif ()
    endif ()
    execute_process(
            COMMAND ${KTEST_RUN_UTEST_INVOKER} ${path} ${run_utest_args}
            WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
            RESULT_VARIABLE run_utest_exit_value
            OUTPUT_FILE "test_output/${target}.out.txt"
            COMMAND_ECHO STDOUT
    )
    execute_process(
            COMMAND ${CMAKE_COMMAND} -E cat test_output/${target}.out.txt
    )
    if (NOT run_utest_exit_value EQUAL 0)
        message(FATAL_ERROR "target: ${target} exit with value: ${run_utest_exit_value}")
    endif ()
    if (DEFINED cached_hash_file_path)
        file(WRITE "${cached_hash_file_path}" "${binary_hash}")
    endif ()
endfunction()


run_utest(
        "${TARGET}" "${PATH}"
        CACHED_HASH_FILE_PATH "${HASH_FILE}"
        RUN_UTEST_ARGS "${RUN_UTEST_ARGS}"
)
