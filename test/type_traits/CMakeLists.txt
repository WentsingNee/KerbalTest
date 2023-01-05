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



add_kerbal_test_target(test.type_traits.is_nothrow_destructible.no_intrinsic is_nothrow_destructible.test.cpp)
target_compile_definitions(test.type_traits.is_nothrow_destructible.no_intrinsic PRIVATE KERBAL_HAS_IS_DESTRUCTIBLE_SUPPORT=0
                                                                                         KERBAL_HAS_IS_NOTHROW_DESTRUCTIBLE_SUPPORT=0)


add_kerbal_test_target(test.type_traits.is_trivially_copy_assignable.no_intrinsic is_trivially_copy_assignable.test.cpp)
target_compile_definitions(test.type_traits.is_trivially_copy_assignable.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_ASSIGNABLE_SUPPORT=0
                                                                                              KERBAL_HAS_IS_TRIVIALLY_COPY_ASSIGNABLE_SUPPORT=0)

add_kerbal_test_target(test.type_traits.is_trivially_copy_constructible.no_intrinsic is_trivially_copy_constructible.test.cpp)
target_compile_definitions(test.type_traits.is_trivially_copy_constructible.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_CONSTRUCTIBLE_SUPPORT=0
                                                                                                 KERBAL_HAS_IS_TRIVIALLY_COPY_CONSTRUCTIBLE_SUPPORT=0)

add_kerbal_test_target(test.type_traits.is_trivially_default_constructible.no_intrinsic is_trivially_default_constructible.test.cpp)
target_compile_definitions(test.type_traits.is_trivially_default_constructible.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_CONSTRUCTIBLE_SUPPORT=0
                                                                                                    KERBAL_HAS_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE_SUPPORT=0)

add_kerbal_test_target(test.type_traits.is_trivially_destructible.no_intrinsic is_trivially_destructible.test.cpp)
target_compile_definitions(test.type_traits.is_trivially_destructible.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_DESTRUCTIBLE_SUPPORT=0)

add_kerbal_test_target(test.type_traits.is_trivially_move_assignable.no_intrinsic is_trivially_move_assignable.test.cpp)
target_compile_definitions(test.type_traits.is_trivially_move_assignable.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_ASSIGNABLE_SUPPORT=0
                                                                                              KERBAL_HAS_IS_TRIVIALLY_MOVE_ASSIGNABLE_SUPPORT=0)

add_kerbal_test_target(test.type_traits.is_trivially_move_constructible.no_intrinsic is_trivially_move_constructible.test.cpp)
target_compile_definitions(test.type_traits.is_trivially_move_constructible.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_CONSTRUCTIBLE_SUPPORT=0
                                                                                                 KERBAL_HAS_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_SUPPORT=0)
