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

foreach (ie IN ITEMS
        avx512f
        avx2
        sse4.1
        sse2
        sve
        neon
)
    add_ktest_utest_target_wih_ie(utest.random.mersenne_twister_engine_${ie} ./mersenne_twister_engine.test.cpp ${ie})
endforeach ()


foreach (ie IN ITEMS
        rdrnd
        arm_rng
)
    add_ktest_utest_target_wih_ie(utest.random.hardware_engine_${ie} ./hardware_engine.test.noauto.cpp ${ie})
endforeach ()
