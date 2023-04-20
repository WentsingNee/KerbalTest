
include(${CMAKE_SOURCE_DIR}/cmake/add_kerbal_parent_target.cmake)

macro(add_kerbal_inst_target target target_src_file)
    add_library(${target} OBJECT ${file})
    add_kerbal_parent_target(${target})
    target_include_directories(${target} PUBLIC "./")
    if (KERBAL_TEST_USE_LIBCXX)
        target_compile_options(${target} PUBLIC -stdlib=libc++)
    endif ()
    set(inst_targets ${inst_targets} ${target})
endmacro()


file(GLOB_RECURSE test_src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (file ${test_src_files})
    string(REGEX MATCH "(.+)\\.inst\\.cpp$" _ ${file})
    if (CMAKE_MATCH_1)
        string(REPLACE "/" "." target ${CMAKE_MATCH_1})
        string(PREPEND target "inst.")
        message("	add: ${target}  <=  ${CMAKE_CURRENT_SOURCE_DIR}/${file}")
        add_kerbal_inst_target(${target} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        set(inst_targets ${inst_targets} PARENT_SCOPE)
    else ()
        message(WARNING "   ${file} has been ignored")
    endif ()
endforeach ()

message("\n")


set(inst_targets_count 0)
foreach (target ${inst_targets})
    message("inst-target ${inst_targets_count}: ${target}")
    math(EXPR inst_targets_count "${inst_targets_count} + 1")
endforeach ()
message("inst targets: ${inst_targets_count}")
message("\n")
