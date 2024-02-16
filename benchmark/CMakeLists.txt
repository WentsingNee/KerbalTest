
include(${PROJECT_SOURCE_DIR}/cmake/add_kerbal_parent_target.cmake)

set(EXECUTABLE_OUTPUT_PATH ./benchmark)

function(add_ktest_bench_target target target_src_file)
    add_executable(${target} ${target_src_file})
    set_target_properties(${target}
            PROPERTIES ktest_category "bench"
    )
    add_kerbal_parent_target(${target})
    set_property(
            GLOBAL
            APPEND
            PROPERTY KTEST_BENCH_TARGETS_MANIFEST "${target}"
    )
    ktest_basic_configuration(${target})

    set_target_properties(${target}
            PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/targets
    )
    if (KERBAL_WASM)
        set_target_properties(${target}
                PROPERTIES RUNTIME_OUTPUT_NAME ${target}.js
        )
    endif ()
    add_test(
            NAME ${target}
            COMMAND ${target}
    )

    # run_bench_target
    set(run_bench_target_name "run_${target}")
    add_custom_target(${run_bench_target_name}
            COMMAND ${path} ${run_bench_args} #> test_output/${target}.out.txt
#            COMMAND ${CMAKE_COMMAND} -E cat test_output/${target}.out.txt
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            COMMENT "Running bench target ${target}"
#            DEPENDS ${target} run_bench_make_test_output_dir
    )

endfunction()


function(add_ktest_bench_target_wih_ie target target_src_file ie)
    if (NOT KERBAL_SUPPORT_${ie})
        message(WARNING "Compiler doesn't support ${ie}")
        return()
    endif ()
    set(target_name_with_ie ${target}.${ie})
    add_ktest_bench_target(${target_name_with_ie} ${target_src_file})
    target_compile_options(${target_name_with_ie} PUBLIC ${KERBAL_TEST_FLAGS_${ie}})
endfunction()



set(instructs sse sse2 avx avx2 avx512f neon sve)

foreach (instruct ${instructs})
    if (NOT KERBAL_SUPPORT_${instruct})
        continue()
    endif ()


    set(target_prefix bench.algorithm.find)
    set(src_file algorithm/find.bench.cpp)

    set(target ${target_prefix}.k)
    add_ktest_bench_target_wih_ie(${target} ${src_file} ${instruct})
    set(target ${target_prefix}.k.${instruct})
    target_compile_definitions(${target} PUBLIC TEST=0)
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./find)

    set(target ${target_prefix}.s)
    add_ktest_bench_target_wih_ie(${target} ${src_file} ${instruct})
    set(target ${target_prefix}.s.${instruct})
    target_compile_definitions(${target} PUBLIC TEST=1)
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./find)



    set(target_prefix bench.algorithm.reverse)
    set(src_file algorithm/reverse.bench.cpp)

    set(target ${target_prefix}.k)
    add_ktest_bench_target_wih_ie(${target} ${src_file} ${instruct})
    set(target ${target_prefix}.k.${instruct})
    target_compile_definitions(${target} PUBLIC TEST=0)
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./reverse)

    set(target ${target_prefix}.s)
    add_ktest_bench_target_wih_ie(${target} ${src_file} ${instruct})
    set(target ${target_prefix}.s.${instruct})
    target_compile_definitions(${target} PUBLIC TEST=1)
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./reverse)
endforeach ()


add_ktest_bench_target(bench.bitset.static_bitset             bitset/static_bitset.bench.cpp)
add_ktest_bench_target(bench.container.vector             container/vector.bench.cpp)



set(bench_targets_count 0)
get_property(
        ktest_bench_targets_manifest
        GLOBAL
        PROPERTY KTEST_BENCH_TARGETS_MANIFEST
)
foreach (target ${ktest_bench_targets_manifest})
    message(VERBOSE "bench-target ${bench_targets_count}: ${target}")
    math(EXPR bench_targets_count "${bench_targets_count} + 1")
endforeach ()
message("bench targets: ${bench_targets_count}")
message("\n")
