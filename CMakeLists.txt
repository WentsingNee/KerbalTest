cmake_minimum_required(VERSION 3.12)
project(KerbalTest CXX)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Platform: ${CMAKE_CXX_PLATFORM_ID}")
message(STATUS "ARCHITECTURE: ${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_HOST_SYSTEM_PROCESSOR: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_TARGET_SYSTEM_PROCESSOR: ${CMAKE_TARGET_SYSTEM_PROCESSOR}")


include_directories(${KERBAL_INCLUDE_DIRECTORY})

message(STATUS "Finding Boost")
find_package(Boost)
message(STATUS "Boost_FOUND: ${Boost_FOUND}")
message(STATUS "Boost_LIB_VERSION: ${Boost_LIB_VERSION}")
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")


option(KERBAL_TEST_USE_LIBCXX "use libc++" OFF)

if (KERBAL_TEST_USE_LIBCXX)
    message(STATUS "Finding libc++")
    find_library(LIB_CPP c++ REQUIRED)
    message(STATUS "Found libc++: ${LIB_CPP}")

    message(STATUS "Finding libc++abi")
    find_library(LIB_CPPABI c++abi REQUIRED)
    message(STATUS "Found libc++abi: ${LIB_CPPABI}")
endif ()


if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/Zc:__cplusplus)
    message(STATUS "CXX flags: /Zc:__cplusplus")

    add_compile_options(/wd4819) # Disable warning C4819, file coding problem
    message(STATUS "CXX flags: /wdC4819")

    add_compile_options(/D_CRT_SECURE_NO_WARNINGS) # Disable warning C4996: 'scanf': This function or variable may be unsafe.
    message(STATUS "CXX flags: /D_CRT_SECURE_NO_WARNINGS")
endif ()


function(add_kerbal_inst_target target target_src_file)
    add_library(${target} OBJECT ${file})
    set_target_properties(${target} PROPERTIES CMAKE_CURRENT_BINARY_DIR ./targets)
    if (KERBAL_TEST_USE_LIBCXX)
        target_compile_options(${target} PUBLIC -stdlib=libc++)
    endif ()
endfunction()


function(add_kerbal_test_target target target_src_file)
    add_executable(${target} ${target_src_file})
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./targets)
    if (KERBAL_TEST_USE_LIBCXX)
        target_compile_options(${target} PUBLIC -stdlib=libc++)
        target_link_libraries(${target} PUBLIC ${LIB_CPP})
        target_link_libraries(${target} PUBLIC ${LIB_CPPABI})
    endif ()
endfunction()


add_subdirectory(./instantiation)
add_subdirectory(./test)
