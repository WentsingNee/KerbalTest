#
# @file       header_include_check.cmake
# @brief
# @date       2023-08-17
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

include(cmake/add_kerbal_parent_target.cmake)

function(add_kerbal_header_check_target target target_src_file)
    set_property(SOURCE "${target_src_file}" PROPERTY LANGUAGE "CXX")
    add_library("${target}" OBJECT ${target_src_file})
    target_compile_options("${target}" PUBLIC -x c++)
    set_target_properties("${target}"
            PROPERTIES ktest_category "header"
    )
    ktest_basic_configuration("${target}")
    add_kerbal_parent_target("${target}")
endfunction()
