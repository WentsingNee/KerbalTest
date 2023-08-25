cmake_minimum_required(VERSION 3.10)
project(KerbalTest CXX)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Platform: ${CMAKE_CXX_PLATFORM_ID}")
message(STATUS "ARCHITECTURE: ${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_HOST_SYSTEM_PROCESSOR: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_TARGET_SYSTEM_PROCESSOR: ${CMAKE_TARGET_SYSTEM_PROCESSOR}")


include_directories(${KERBAL_INCLUDE_DIRECTORY})


# compiler global configuration

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
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/Zc:__cplusplus)
    message(STATUS "CXX flags: /Zc:__cplusplus")

    add_compile_options(/wd4819) # Disable warning C4819, file coding problem
    message(STATUS "CXX flags: /wdC4819")

    add_compile_options(/D_CRT_SECURE_NO_WARNINGS) # Disable warning C4996: 'scanf': This function or variable may be unsafe.
    message(STATUS "CXX flags: /D_CRT_SECURE_NO_WARNINGS")
endif ()

if (${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.12")
    add_compile_definitions(KERBAL_TYPE_TRAITS_DEBUG_WARNING=1)
endif ()


# instruction extensions

option(KERBAL_TEST_ENABLE_IE "enable instruction extensions" ON)

if (KERBAL_TEST_ENABLE_IE)
    include(cmake/instruction_extensions.cmake)
endif ()


# libc++

option(KERBAL_TEST_USE_LIBCXX "use libc++" OFF)

if (KERBAL_TEST_USE_LIBCXX)
    message(STATUS "Finding libc++")
    find_library(LIB_CPP c++ REQUIRED)
    message(STATUS "Found libc++: ${LIB_CPP}")

    message(STATUS "Finding libc++abi")
    find_library(LIB_CPPABI c++abi REQUIRED)
    message(STATUS "Found libc++abi: ${LIB_CPPABI}")
endif ()


# sanitize

option(KERBAL_TEST_ENABLE_SANITIZE "enable sanitize" OFF)

if (KERBAL_TEST_ENABLE_SANITIZE)
    message(STATUS "Finding libasan")
    find_library(LIB_ASAN asan REQUIRED)
    message(STATUS "Found libasan: ${LIB_ASAN}")

    message(STATUS "Finding libubsan")
    find_library(LIB_UBSAN ubsan REQUIRED)
    message(STATUS "Found libubsan: ${LIB_UBSAN}")
endif ()


# gcov

option(KERBAL_TEST_ENABLE_GCOV "enable gcov" OFF)


add_subdirectory(instantiation)
add_subdirectory(test)
