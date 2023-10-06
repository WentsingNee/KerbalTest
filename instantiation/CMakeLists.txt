
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/add_kerbal_parent_target.cmake)

function(add_kerbal_inst_target_impl target target_src_file)
    add_library(${target} OBJECT ${file})
    add_kerbal_parent_target(${target})
    target_link_libraries(${target} PUBLIC Kerbal::kerbal)
    target_include_directories(${target} PUBLIC "${PROJECT_SOURCE_DIR}/include")
    if (KERBAL_TEST_USE_LIBCXX)
        target_compile_options(${target} PUBLIC -stdlib=libc++)
    endif ()
endfunction()

macro(add_kerbal_inst_target target target_src_file)
    add_kerbal_inst_target_impl(${target} ${target_src_file})
    list(APPEND inst_targets ${target})
endmacro()


file(GLOB_RECURSE test_src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (file ${test_src_files})
    if (NOT file MATCHES "(.+)\\.inst\\.cpp$")
        string(APPEND ignored_inst_src_files "${CMAKE_CURRENT_SOURCE_DIR}/${file}:0\n")
        continue()
    endif ()
    string(REPLACE "/" "." target ${CMAKE_MATCH_1})
    string(PREPEND target "inst.")
    message(VERBOSE "	add: ${target}  <=  ${CMAKE_CURRENT_SOURCE_DIR}/${file}")
    add_kerbal_inst_target(${target} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    if (${KERBAL_TEST_ENABLE_PRECOMPILE_HEADER})
        target_precompile_headers(${target} REUSE_FROM kerbal_test_precompile_header)
    endif ()
    set(inst_targets ${inst_targets} PARENT_SCOPE)
endforeach ()

message("\n")

message(WARNING "These files have been ignored:")
message(STATUS "${ignored_inst_src_files}")


set(inst_targets_count 0)
foreach (target ${inst_targets})
    message(VERBOSE "inst-target ${inst_targets_count}: ${target}")
    math(EXPR inst_targets_count "${inst_targets_count} + 1")
endforeach ()
message("inst targets: ${inst_targets_count}")
message("\n")
