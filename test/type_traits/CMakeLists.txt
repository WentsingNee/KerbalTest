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

set(try_test_guess_list
        is_enum

        is_assignable
        is_constructible
#        is_copy_assignable
#        is_copy_constructible
#        is_default_constructible
        is_destructible
#        is_move_assignable
#        is_move_constructible

#        is_nothrow_assignable
#        is_nothrow_constructible
        is_nothrow_copy_assignable
        is_nothrow_copy_constructible
        is_nothrow_default_constructible
        is_nothrow_destructible
        is_nothrow_move_assignable
        is_nothrow_move_constructible

#        is_trivially_assignable
#        is_trivially_constructible
        is_trivially_copy_assignable
        is_trivially_copy_constructible
        is_trivially_default_constructible
        is_trivially_destructible
        is_trivially_move_assignable
        is_trivially_move_constructible
)

foreach (e ${try_test_guess_list})
    add_kerbal_utest_target(utest.type_traits.${e}_guess ${e}.test.cpp)
    string(TOUPPER ${e} E)
    target_compile_definitions(utest.type_traits.${e}_guess PRIVATE KERBAL_HAS_${E}_SUPPORT=0)
endforeach ()

set(test_targets ${test_targets} PARENT_SCOPE)
