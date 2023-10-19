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

set(
        kerbal_random_mt_supported_IEs
        avx512f
        avx2
        sse4.1
        sse2
        sve
        neon
)

foreach (ie ${kerbal_random_mt_supported_IEs})
    add_ktest_utest_target_wih_ie(utest.random.mersenne_twister_engine ./mersenne_twister_engine.test.cpp ${ie})
endforeach ()

set(test_targets ${test_targets} PARENT_SCOPE)
