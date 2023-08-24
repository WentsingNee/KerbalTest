#
# @file       coroutine.cmake
# @brief
# @date       2022-12-09
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

include(CheckCXXCompilerFlag)

message("\n")
message(STATUS "Checking compiler's support for coroutine")
message("")

macro(check_compiler_support_coroutine_flag)
    set(flag ${ARGN})
    message(STATUS "Checking compiler support coroutine flag: ${flag}")
    CHECK_CXX_COMPILER_FLAG("${flag}" KERBAL_TEST_SUPPORT_COROUTINE)
    message(STATUS "Checking compiler support coroutine flag: ${flag} - Done")
    message(STATUS "set KERBAL_TEST_SUPPORT_COROUTINE = ${KERBAL_TEST_SUPPORT_COROUTINE}")
    if (${KERBAL_TEST_SUPPORT_COROUTINE})
        set(KERBAL_TEST_FLAG_COROUTINE ${flag} PARENT_SCOPE)
        message(STATUS "set KERBAL_TEST_COROUTINE_FLAGS = ${flag}")
    endif ()
    message("")
endmacro()


function(try_test_compiler_coroutine_support)
    check_compiler_support_coroutine_flag(-fcoroutines)
    if (KERBAL_TEST_SUPPORT_COROUTINE)
        return()
    endif ()

    message(STATUS "-fcoroutines doesn't support, try: -fcoroutines-ts")
    unset(KERBAL_TEST_SUPPORT_COROUTINE CACHE)
    check_compiler_support_coroutine_flag(-fcoroutines-ts)
    message("\n")

endfunction()

try_test_compiler_coroutine_support()


