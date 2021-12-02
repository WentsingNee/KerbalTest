cmake_minimum_required(VERSION 3.12)
project(KerbalTest CXX)

message(Compiler: ${CMAKE_CXX_COMPILER_ID})
message(Platform: ${CMAKE_CXX_PLATFORM_ID})
message(ARCHITECTURE: ${CMAKE_CXX_COMPILER_ARCHITECTURE_ID})
message(CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR})
message(CMAKE_HOST_SYSTEM_PROCESSOR: ${CMAKE_HOST_SYSTEM_PROCESSOR})
message(CMAKE_TARGET_SYSTEM_PROCESSOR: ${CMAKE_TARGET_SYSTEM_PROCESSOR})

include_directories(${KERBAL_INCLUDE_DIRECTORY})

if (CMAKE_CXX_PLATFORM_ID MATCHES "Linux")
    message("linux")
elseif (CMAKE_CXX_PLATFORM_ID MATCHES "MinGW" OR CMAKE_CXX_PLATFORM_ID MATCHES "Windows")
    message("windows")
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "/Zc:__cplusplus ${CMAKE_CXX_FLAGS}")
    message(STATUS "CXX flags: /Zc:__cplusplus")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4819") # Disable warning C4819, file coding problem
    message(STATUS "CXX flags: /wdC4819")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_CRT_SECURE_NO_WARNINGS") # Disable warning C4996: 'scanf': This function or variable may be unsafe.
    message(STATUS "CXX flags: /D_CRT_SECURE_NO_WARNINGS")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    add_compile_definitions(__GNUC__=10)
    add_compile_options(-isystem /usr/include/c++/10/)
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
        target_link_libraries(${target} PUBLIC c++)
        target_link_libraries(${target} PUBLIC c++abi)
    endif ()
endfunction()


add_subdirectory(./instantiation)
add_subdirectory(./test)
