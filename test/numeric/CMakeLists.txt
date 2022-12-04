#
# @file       CMakeLists.txt
# @brief
# @date       2022-12-02
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

foreach (ie IN ITEMS bmi2 avx2 sse2 mmx neon)
    add_ktest_utest_target_wih_ie(utest.numeric.bit_${ie} ./bit.test.cpp ${ie})
endforeach ()
