set(EXECUTABLE_OUTPUT_PATH ./benchmark)



macro(add_kerbal_bench_target target target_src_file)
    add_executable(${target} ${target_src_file})
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/targets)
    target_include_directories(${target} PUBLIC ./)
    if (KERBAL_TEST_USE_LIBCXX)
        target_compile_options(${target} PUBLIC -stdlib=libc++)
        target_link_libraries(${target} PUBLIC ${LIB_CPP})
        target_link_libraries(${target} PUBLIC ${LIB_CPPABI})
    endif ()
    add_test(
            NAME ${target}
            COMMAND ${target}
    )
    set(bench_targets ${bench_targets} ${target})
endmacro()


macro(add_kerbal_bench_target_wih_ie target target_src_file ie)
    if (${KERBAL_TEST_SUPPORT_${ie}})
        set(target_name_with_ie ${target}.${ie})
        add_kerbal_bench_target(${target_name_with_ie} ${target_src_file})
        target_compile_options(${target_name_with_ie} PUBLIC ${KERBAL_TEST_FLAGS_${ie}})
    else ()
        message(WARNING "Compiler doesn't support ${ie}")
    endif ()
endmacro()


set(instructs sse sse2 avx avx2 avx512f neon sve)


foreach (instruct ${instructs})
    if (${KERBAL_TEST_SUPPORT_${instruct}})
    else()
        continue()
    endif ()


    set(target_prefix bench.algorithm.find)
    set(src_file algorithm/find.bench.cpp)

    set(target ${target_prefix}.k)
    add_kerbal_bench_target_wih_ie(${target} ${src_file} ${instruct})
    set(target ${target_prefix}.k.${instruct})
    target_compile_definitions(${target} PUBLIC TEST=0)
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./find)

    set(target ${target_prefix}.s)
    add_kerbal_bench_target_wih_ie(${target} ${src_file} ${instruct})
    set(target ${target_prefix}.s.${instruct})
    target_compile_definitions(${target} PUBLIC TEST=1)
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./find)



    set(target_prefix bench.algorithm.reverse)
    set(src_file algorithm/reverse.bench.cpp)

    set(target ${target_prefix}.k)
    add_kerbal_bench_target_wih_ie(${target} ${src_file} ${instruct})
    set(target ${target_prefix}.k.${instruct})
    target_compile_definitions(${target} PUBLIC TEST=0)
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./reverse)

    set(target ${target_prefix}.s)
    add_kerbal_bench_target_wih_ie(${target} ${src_file} ${instruct})
    set(target ${target_prefix}.s.${instruct})
    target_compile_definitions(${target} PUBLIC TEST=1)
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./reverse)
endforeach ()


add_kerbal_bench_target(bench.bitset.static_bitset             bitset/static_bitset.bench.cpp)
add_kerbal_bench_target(bench.container.vector             container/vector.bench.cpp)



set(bench_targets_count 0)
foreach (target ${bench_targets})
    message(VERBOSE "test-target ${bench_targets_count}: ${target}")
    math(EXPR bench_targets_count "${bench_targets_count} + 1")
endforeach ()
message("test targets: ${bench_targets_count}")
message("\n")


# ctest
enable_testing()
