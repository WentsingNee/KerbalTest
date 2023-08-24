#
# @file       CMakeLists.txt
# @brief
# @date       2022-12-09
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

macro(target_wih_coroutine target target_src_file)
    if (${KERBAL_TEST_SUPPORT_COROUTINE})
        target_compile_options(${target} PUBLIC ${KERBAL_TEST_FLAG_COROUTINE})
        message(STATUS "target ${target} with coroutine flag: ${KERBAL_TEST_FLAG_COROUTINE}")
    else()
        message(WARNING "${target} has been ignored because compiler doesn't support coroutine")
    endif()
endmacro()

target_wih_coroutine(test.coroutine.generator ./generator.test.cpp)
target_wih_coroutine(test.coroutine.lazy ./lazy.test.cpp)
target_wih_coroutine(test.coroutine.task ./task.test.cpp)
