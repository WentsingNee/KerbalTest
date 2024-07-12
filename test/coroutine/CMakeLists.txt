#
# @file       CMakeLists.txt
# @brief
# @date       2022-12-09
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

function(ktest_add_coroutine_target target target_src_file)
    if (NOT KERBAL_SUPPORT_COROUTINE)
        message(WARNING "${target} has been ignored because compiler doesn't support coroutine")
        return()
    endif ()
    add_ktest_utest_target(${target} ${target_src_file})
    kerbal_target_with_coroutine(
            TARGET ${target}
            SCOPE PUBLIC
            MODE REQUIRED
    )
#    target_link_libraries(${target}
#        INTERFACE
#            kerbal-coroutine
#    )
endfunction()


if (KERBAL_SUPPORT_COROUTINE)
    ktest_add_coroutine_target(test.coroutine.generator    ./generator.test.noauto.cpp)
    ktest_add_coroutine_target(test.coroutine.lazy         ./lazy.test.noauto.cpp)
    ktest_add_coroutine_target(test.coroutine.task         ./task.test.noauto.cpp)
endif ()
