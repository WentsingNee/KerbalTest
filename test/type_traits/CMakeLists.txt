#
# @file       CMakeLists.txt
# @brief
# @date       2023-01-03
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

add_kerbal_test_target(test.type_traits.is_destructible.limited is_destructible.test.cpp)
target_compile_definitions(test.type_traits.is_destructible.limited PRIVATE KERBAL_TRY_TEST_IS_DESTRUCTIBLE_POLICY=KERBAL_TRY_TEST_IS_DESTRUCTIBLE_POLICY_LIMITED)

add_kerbal_test_target(test.type_traits.is_destructible.void_type is_destructible.test.cpp)
target_compile_definitions(test.type_traits.is_destructible.void_type PRIVATE KERBAL_TRY_TEST_IS_DESTRUCTIBLE_POLICY=KERBAL_TRY_TEST_IS_DESTRUCTIBLE_POLICY_VOID_TYPE)
