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

set(try_test_guess
        is_enum

        is_assignable
        is_constructible
        is_destructible

#        is_nothrow_assignable
#        is_nothrow_constructible
        is_nothrow_copy_assignable
        is_nothrow_copy_constructible
        is_nothrow_default_constructible
        is_nothrow_destructible
#        is_nothrow_move_assignable
#        is_nothrow_move_constructible

#        is_trivially_assignable
#        is_trivially_constructible
        is_trivially_copy_assignable
        is_trivially_copy_constructible
        is_trivially_default_constructible
        is_trivially_destructible
        is_trivially_move_assignable
        is_trivially_move_constructible
)

foreach (e ${try_test_guess})
    add_kerbal_test_target(test.type_traits.${e}_guess ${e}.test.cpp)
    string(TOUPPER ${e} E)
    message(STATUS "fff   ${e}   ${E}")
    target_compile_definitions(test.type_traits.${e}_guess PRIVATE KERBAL_HAS_${E}_SUPPORT=0)
endforeach ()


add_kerbal_test_target(test.type_traits.is_assignable_intrin is_assignable.test.cpp)
target_compile_definitions(test.type_traits.is_assignable_intrin PRIVATE KERBAL_TEST_IS_ASSIGNABLE_POLICY=KERBAL_TEST_IS_ASSIGNABLE_POLICY_INTRIN)

add_kerbal_test_target(test.type_traits.is_assignable_void_type is_assignable.test.cpp)
target_compile_definitions(test.type_traits.is_assignable_void_type PRIVATE KERBAL_TEST_IS_ASSIGNABLE_POLICY=KERBAL_TEST_IS_ASSIGNABLE_POLICY_VOIDDTYPE)



add_kerbal_test_target(test.type_traits.is_destructible_intrin is_destructible.test.cpp)
target_compile_definitions(test.type_traits.is_destructible_intrin PRIVATE KERBAL_TEST_IS_DESTRUCTIBLE_POLICY=KERBAL_TEST_IS_DESTRUCTIBLE_POLICY_INTRIN)

add_kerbal_test_target(test.type_traits.is_destructible_void_type is_destructible.test.cpp)
target_compile_definitions(test.type_traits.is_destructible_void_type PRIVATE KERBAL_TEST_IS_DESTRUCTIBLE_POLICY=KERBAL_TEST_IS_DESTRUCTIBLE_POLICY_VOIDDTYPE)



add_kerbal_test_target(test.type_traits.is_nothrow_destructible_intrin is_nothrow_destructible.test.cpp)
target_compile_definitions(test.type_traits.is_nothrow_destructible_intrin PRIVATE KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY=KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY_INTRIN)

add_kerbal_test_target(test.type_traits.is_nothrow_destructible_traits11 is_nothrow_destructible.test.cpp)
target_compile_definitions(test.type_traits.is_nothrow_destructible_traits11 PRIVATE KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY=KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY_TRAITS11)


#add_kerbal_test_target(test.type_traits.is_nothrow_destructible.no_intrinsic is_nothrow_destructible.test.cpp)
#target_compile_definitions(test.type_traits.is_nothrow_destructible.no_intrinsic PRIVATE KERBAL_HAS_IS_DESTRUCTIBLE_SUPPORT=0
#                                                                                         KERBAL_HAS_IS_NOTHROW_DESTRUCTIBLE_SUPPORT=0)
#
#
#add_kerbal_test_target(test.type_traits.is_trivially_copy_assignable.no_intrinsic is_trivially_copy_assignable.test.cpp)
#target_compile_definitions(test.type_traits.is_trivially_copy_assignable.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_ASSIGNABLE_SUPPORT=0
#                                                                                              KERBAL_HAS_IS_TRIVIALLY_COPY_ASSIGNABLE_SUPPORT=0)
#
#add_kerbal_test_target(test.type_traits.is_trivially_copy_constructible.no_intrinsic is_trivially_copy_constructible.test.cpp)
#target_compile_definitions(test.type_traits.is_trivially_copy_constructible.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_CONSTRUCTIBLE_SUPPORT=0
#                                                                                                 KERBAL_HAS_IS_TRIVIALLY_COPY_CONSTRUCTIBLE_SUPPORT=0)
#
#add_kerbal_test_target(test.type_traits.is_trivially_default_constructible.no_intrinsic is_trivially_default_constructible.test.cpp)
#target_compile_definitions(test.type_traits.is_trivially_default_constructible.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_CONSTRUCTIBLE_SUPPORT=0
#                                                                                                    KERBAL_HAS_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE_SUPPORT=0)
#
#add_kerbal_test_target(test.type_traits.is_trivially_destructible.no_intrinsic is_trivially_destructible.test.cpp)
#target_compile_definitions(test.type_traits.is_trivially_destructible.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_DESTRUCTIBLE_SUPPORT=0)
#
#add_kerbal_test_target(test.type_traits.is_trivially_move_assignable.no_intrinsic is_trivially_move_assignable.test.cpp)
#target_compile_definitions(test.type_traits.is_trivially_move_assignable.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_ASSIGNABLE_SUPPORT=0
#                                                                                              KERBAL_HAS_IS_TRIVIALLY_MOVE_ASSIGNABLE_SUPPORT=0)
#
#add_kerbal_test_target(test.type_traits.is_trivially_move_constructible.no_intrinsic is_trivially_move_constructible.test.cpp)
#target_compile_definitions(test.type_traits.is_trivially_move_constructible.no_intrinsic PRIVATE KERBAL_HAS_IS_TRIVIALLY_CONSTRUCTIBLE_SUPPORT=0
#                                                                                                 KERBAL_HAS_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_SUPPORT=0)
