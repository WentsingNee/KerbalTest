#
# @file       CMakeLists.txt
# @brief
# @date       2024-02-17
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

foreach (
        ie IN ITEMS
        sse2 ssse3 avx2
)
    add_ktest_utest_target_wih_ie("utest.algorithm.modifier.reverse_${ie}" reverse.test.cpp ${ie})
endforeach ()
