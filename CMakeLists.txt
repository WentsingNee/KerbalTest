cmake_minimum_required(VERSION 3.10)
project(KerbalTest CXX)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Platform: ${CMAKE_CXX_PLATFORM_ID}")
message(STATUS "ARCHITECTURE: ${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_HOST_SYSTEM_PROCESSOR: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_TARGET_SYSTEM_PROCESSOR: ${CMAKE_TARGET_SYSTEM_PROCESSOR}")


include_directories(${KERBAL_INCLUDE_DIRECTORY})

include(cmake/get_kerbal_public_headers.cmake)
get_kerbal_public_headers("${KERBAL_INCLUDE_DIRECTORY}" kerbal_public_headers)


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

add_compile_definitions(LITTLE_ENDIAN=0)
add_compile_definitions(BIG_ENDIAN=1)
add_compile_definitions(BYTE_ORDER=LITTLE_ENDIAN)

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


# precompile header

option(KERBAL_TEST_ENABLE_PRECOMPILE_HEADER "enable precompile header" OFF)

if (${KERBAL_TEST_ENABLE_PRECOMPILE_HEADER})

    list(LENGTH kerbal_public_headers kerbal_public_headers_len)

    if (kerbal_public_headers_len EQUAL 0)
        message(WARNING "you should provide variable KERBAL_INCLUDE_DIRECTORY correctly to support precompile header")
        set(KERBAL_TEST_ENABLE_PRECOMPILE_HEADER OFF)
    endif ()

    file(WRITE "${CMAKE_BINARY_DIR}/kerbal_test_pch.cpp" "")
    add_library(kerbal_test_precompile_header OBJECT kerbal_test_pch.cpp)
    if (KERBAL_TEST_USE_LIBCXX)
        target_compile_options(kerbal_test_precompile_header PUBLIC -stdlib=libc++)
        target_link_libraries(kerbal_test_precompile_header PUBLIC ${LIB_CPP})
        target_link_libraries(kerbal_test_precompile_header PUBLIC ${LIB_CPPABI})
    endif ()
    foreach (header ${kerbal_public_headers})
        target_precompile_headers(kerbal_test_precompile_header PUBLIC "${KERBAL_INCLUDE_DIRECTORY}${header}")
    endforeach ()
endif ()


add_subdirectory(instantiation)
add_subdirectory(test)
