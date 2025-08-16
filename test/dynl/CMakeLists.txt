#
# @file       CMakeLists.txt
# @brief
# @date       2025-08-16
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#


add_library(
        utest.dynl.simu_lib SHARED
        "${CMAKE_CURRENT_SOURCE_DIR}/simu_lib/simu_lib.cpp"
)

add_kerbal_parent_target(utest.dynl.simu_lib)
