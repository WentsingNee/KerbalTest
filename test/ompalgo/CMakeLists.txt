
function(add_kerbal_ompalgo_test_target target target_src_file)
    add_kerbal_test_target(${target} ${target_src_file})
    target_compile_options(${target} PUBLIC -fopenmp)
    target_link_libraries(${target} PUBLIC omp)
endfunction()


add_kerbal_ompalgo_test_target(test.ompalgo.querier                      querier.test.cpp)

