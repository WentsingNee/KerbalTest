set(EXECUTABLE_OUTPUT_PATH ./benchmark)

include_directories(../)
set(targets)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    add_compile_options(-Wall)
    message(STATUS "CXX flags: -Wall")

    add_compile_options(-Wextra)
    message(STATUS "CXX flags: -Wextra")

    add_compile_options(-Wno-unused-parameter)
    message(STATUS "CXX flags: -Wno-unused-parameter")

    if (${CMAKE_CXX_STANDARD} MATCHES 98)
        add_compile_definitions(LITTLE_ENDIAN=0)
        add_compile_definitions(BIG_ENDIAN=1)
        add_compile_definitions(BYTE_ORDER=LITTLE_ENDIAN)
    endif ()

endif ()


set(instructs sse avx avx2 avx512f)


foreach (instruct ${instructs})
    set(target_prefix bench.algorithm.find)
    set(src_file algorithm/find.bench.cpp)

    set(target ${target_prefix}.k.${instruct})
    add_executable(${target} ${src_file})
    target_compile_definitions(${target} PUBLIC TEST=0)
    target_compile_options(${target} PUBLIC -m${instruct})
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./find)

    set(target ${target_prefix}.s.${instruct})
    add_executable(${target} ${src_file})
    target_compile_definitions(${target} PUBLIC TEST=1)
    target_compile_options(${target} PUBLIC -m${instruct})
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./find)
endforeach ()


foreach (instruct ${instructs})
    set(target_prefix bench.algorithm.reverse)
    set(src_file algorithm/reverse.bench.cpp)

    set(target ${target_prefix}.k.${instruct})
    add_executable(${target} ${src_file})
    target_compile_definitions(${target} PUBLIC TEST=0)
    target_compile_options(${target} PUBLIC -m${instruct})
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./reverse)

    set(target ${target_prefix}.s.${instruct})
    add_executable(${target} ${src_file})
    target_compile_definitions(${target} PUBLIC TEST=1)
    target_compile_options(${target} PUBLIC -m${instruct})
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./reverse)
endforeach ()


message("\n")

foreach (target ${targets})
    message("target: " ${target})
endforeach ()

message("\n")


add_kerbal_test_target(bench.bitset.static_bitset             bitset/static_bitset.bench.cpp)
add_kerbal_test_target(bench.container.vector             container/vector.bench.cpp)
