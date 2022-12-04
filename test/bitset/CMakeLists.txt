#
# @file       CMakeLists.txt
# @brief
# @date       2022-12-04
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

foreach (ie IN ITEMS avx512f avx2 avx sse4.1 sve neon)
    add_ktest_utest_target_wih_ie(utest.bitset.static_bitset_${ie} ./static_bitset.test.cpp ${ie})
endforeach ()
