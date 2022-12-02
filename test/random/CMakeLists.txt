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

add_kerbal_test_target_wih_ie(test.random.mersenne_twister_engine ./mersenne_twister_engine.test.cpp avx512f)
add_kerbal_test_target_wih_ie(test.random.mersenne_twister_engine ./mersenne_twister_engine.test.cpp avx2)
add_kerbal_test_target_wih_ie(test.random.mersenne_twister_engine ./mersenne_twister_engine.test.cpp sse2)
add_kerbal_test_target_wih_ie(test.random.mersenne_twister_engine ./mersenne_twister_engine.test.cpp sve)
add_kerbal_test_target_wih_ie(test.random.mersenne_twister_engine ./mersenne_twister_engine.test.cpp neon)

set(test_targets ${test_targets} PARENT_SCOPE)
