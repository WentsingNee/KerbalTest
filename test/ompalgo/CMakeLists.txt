#
# @file       CMakeLists.txt
# @brief
# @date       2023-6-10
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#


if (NOT TARGET Kerbal::kerbal-omp)
    message(WARNING "Kerbal::kerbal-omp target is not exist, utests under ompalgo will be skipped")
endif ()


function(add_ktest_ompalgo_utest_target target target_src_file)
    if (NOT TARGET Kerbal::kerbal-omp)
        continue()
    endif ()
    add_ktest_utest_target("${target}" "${target_src_file}")
    target_link_libraries("${target}" PUBLIC Kerbal::kerbal-omp)
endfunction()


add_ktest_ompalgo_utest_target(utest.ompalgo.countif                      countif.test.noauto.cpp)
add_ktest_ompalgo_utest_target(utest.ompalgo.foreach                      foreach.test.noauto.cpp)
add_ktest_ompalgo_utest_target(utest.ompalgo.sort                         sort.test.noauto.cpp)
