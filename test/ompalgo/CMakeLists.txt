
#cmake_policy(SET CMP0079 NEW)

message(STATUS "Finding library omp...")
find_library(libomp omp)

if (${libomp})
    message(STATUS "Finding library omp -- Found: ${libomp}")
    set(KERBAL_ENABLE_SUBLIB_OMP_UTEST TRUE)
else ()
    message(STATUS "Finding library omp -- Not FOUND")
    set(KERBAL_ENABLE_SUBLIB_OMP_UTEST FALSE)
endif ()

macro(add_kerbal_ompalgo_utest_target target target_src_file)
    if (KERBAL_ENABLE_SUBLIB_OMP_UTEST)
        target_compile_options(${target} PUBLIC -fopenmp)
        target_link_libraries(${target} PUBLIC ${libomp})
    endif ()
endmacro()


add_kerbal_ompalgo_utest_target(utest.ompalgo.querier                      querier.test.cpp)

