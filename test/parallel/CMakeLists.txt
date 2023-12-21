#
# @file       CMakeLists.txt
# @brief
# @date       2024-04-03
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

include(FindThreads)

if (NOT Threads_FOUND)
    return()
endif ()

add_ktest_utest_target(utest.parallel.thread_pool thread_pool.test.noauto.cpp)
target_link_libraries(utest.parallel.thread_pool PRIVATE Kerbal::kerbal-parallel)
