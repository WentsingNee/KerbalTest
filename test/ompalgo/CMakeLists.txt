
cmake_policy(SET CMP0079 NEW)

message(STATUS "Finding library omp...")
find_library(libomp omp REQUIRED)
message(STATUS "Finding library omp -- FOUND ${libomp}")

macro(add_kerbal_ompalgo_test_target target target_src_file)
    target_compile_options(${target} PUBLIC -fopenmp)
    target_link_libraries(${target} PUBLIC ${libomp})
endmacro()


add_kerbal_ompalgo_test_target(test.ompalgo.querier                      querier.test.cpp)

