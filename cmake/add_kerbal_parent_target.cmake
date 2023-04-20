#
# @file       add_kerbal_parent_target.cmake
# @brief
# @date       2023-04-21
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#


function(add_kerbal_parent_target target)
    string(FIND "${target}" "." pos REVERSE)
    if (pos EQUAL -1)
        return ()
    endif ()
    string(SUBSTRING "${target}" 0 ${pos} parent_target_name)
    if (${parent_target_name} STREQUAL "test") # On CMake 3.10, target with name `test` is reserved
        set (parent_target_name "utest")
    endif ()
    if (NOT TARGET ${parent_target_name})
        add_custom_target(${parent_target_name})
        add_kerbal_parent_target(${parent_target_name})
    endif ()
    add_dependencies(${parent_target_name} ${target})
endfunction()
