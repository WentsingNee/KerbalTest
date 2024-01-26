
include(${PROJECT_SOURCE_DIR}/cmake/add_kerbal_parent_target.cmake)

function(add_ktest_inst_target target target_src_file)
    add_library(${target} OBJECT ${file})
    set_target_properties(${target}
            PROPERTIES ktest_category "instantiation"
    )
    add_kerbal_parent_target(${target})
    set_property(
            GLOBAL
            APPEND
            PROPERTY KTEST_INST_TARGETS_MANIFEST "${target}"
    )
    ktest_basic_configuration(${target})
endfunction()


file(GLOB_RECURSE test_src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (file ${test_src_files})
    if (NOT file MATCHES "(.+)\\.inst\\.cpp$")
        string(APPEND ignored_inst_src_files "${CMAKE_CURRENT_SOURCE_DIR}/${file}:0\n")
        continue()
    endif ()
    string(REPLACE "/" "." target ${CMAKE_MATCH_1})
    string(PREPEND target "inst.")
    message(VERBOSE "	add: ${target}  <=  ${CMAKE_CURRENT_SOURCE_DIR}/${file}")
    add_ktest_inst_target(${target} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    if (${KTEST_ENABLE_PRECOMPILE_HEADER})
        target_precompile_headers(${target} REUSE_FROM ktest_precompile_header)
    endif ()
endforeach ()

message("\n")

message(WARNING "These files have been ignored:")
message(STATUS "${ignored_inst_src_files}")


set(inst_targets_count 0)
get_property(
        ktest_inst_targets_manifest
        GLOBAL
        PROPERTY KTEST_INST_TARGETS_MANIFEST
)
foreach (target ${ktest_inst_targets_manifest})
    message(VERBOSE "inst-target ${inst_targets_count}: ${target}")
    math(EXPR inst_targets_count "${inst_targets_count} + 1")
endforeach ()
message("inst targets: ${inst_targets_count}")
message("\n")
