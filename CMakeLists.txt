cmake_minimum_required(VERSION 3.10)
project(KerbalTest CXX)

message(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "CMAKE_CROSSCOMPILING: ${CMAKE_CROSSCOMPILING}")
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_PLATFORM_ID: ${CMAKE_CXX_PLATFORM_ID}")
message(STATUS "CMAKE_CXX_COMPILER_ARCHITECTURE_ID: ${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}")
message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_HOST_SYSTEM_NAME: ${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "CMAKE_HOST_SYSTEM_PROCESSOR: ${CMAKE_HOST_SYSTEM_PROCESSOR}")


if (NOT TARGET Kerbal::kerbal)
    message(STATUS "Finding Kerbal")
    find_package(Kerbal REQUIRED)
    message(STATUS "Finding Kerbal -- found")
endif ()

message(STATUS "Kerbal_VERSION: ${Kerbal_VERSION}")
message(STATUS "Kerbal_INCLUDE_DIRS: ${Kerbal_INCLUDE_DIRS}")


# instruction extensions

option(KTEST_ENABLE_IE "enable instruction extensions" ON)

if (KTEST_ENABLE_IE)
    include(Kerbal/instruction_extensions)
    kerbal_ies_required(${KERBAL_IE_LIST})
endif ()


# libc++

option(KTEST_USE_LIBCXX "use libc++" OFF)

if (KTEST_USE_LIBCXX)
    message(STATUS "Finding libc++")
    find_library(KTEST_LIB_CPP c++ REQUIRED)
    message(STATUS "Found libc++: ${KTEST_LIB_CPP}")

    message(STATUS "Finding libc++abi")
    find_library(KTEST_LIB_CPPABI c++abi REQUIRED)
    message(STATUS "Found libc++abi: ${KTEST_LIB_CPPABI}")
endif ()


# sanitize

option(KTEST_ENABLE_SANITIZE "enable sanitize" OFF)

if (KTEST_ENABLE_SANITIZE)
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        if (CMAKE_VS_PLATFORM_NAME MATCHES "Win32" OR CMAKE_CXX_COMPILER_ARCHITECTURE_ID MATCHES "X86")
            set(msvc_lib_architecture_suffix "i386")
        elseif (CMAKE_VS_PLATFORM_NAME MATCHES "x64" OR CMAKE_CXX_COMPILER_ARCHITECTURE_ID MATCHES "x64")
            set(msvc_lib_architecture_suffix "x86_64")
        else ()
            message(FATAL_ERROR "Could not deduce msvc_lib_architecture_suffix")
        endif ()

        message(STATUS "Finding libasan")
        find_library(KTEST_LIB_ASAN "clang_rt.asan_dynamic-${msvc_lib_architecture_suffix}" REQUIRED)
        message(STATUS "Found libasan: ${KTEST_LIB_ASAN}")

        message(STATUS "Finding libasan.dll")
        find_file(KTEST_LIB_ASAN_DLL "clang_rt.asan_dynamic-${msvc_lib_architecture_suffix}.dll" REQUIRED)
        message(STATUS "Found libasan.dll: ${KTEST_LIB_ASAN_DLL}")
    else ()
        message(STATUS "Finding libasan")
        find_library(KTEST_LIB_ASAN asan REQUIRED)
        message(STATUS "Found libasan: ${KTEST_LIB_ASAN}")

        message(STATUS "Finding libubsan")
        find_library(KTEST_LIB_UBSAN ubsan REQUIRED)
        message(STATUS "Found libubsan: ${KTEST_LIB_UBSAN}")
    endif ()
endif ()


# gcov

option(KTEST_ENABLE_GCOV "enable gcov" OFF)


# basic configuration

function(ktest_basic_configuration target)
    get_target_property(ktest_category ${target} "ktest_category")


    # compiler global configuration

    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
        CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID MATCHES "Intel"
    )
        target_compile_options(
                ${target} PUBLIC
                -Wall
                -Wextra
                -Wno-unused-parameter
        )
    elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        target_compile_options(${target} PUBLIC /Zc:__cplusplus)
        target_compile_options(${target} PUBLIC /wd4819) # Disable warning C4819, file coding problem
        target_compile_definitions(${target} PUBLIC _CRT_SECURE_NO_WARNINGS) # Disable warning C4996: 'scanf': This function or variable may be unsafe.
    endif ()

    target_compile_definitions(
            ${target} PUBLIC
            LITTLE_ENDIAN=0
            BIG_ENDIAN=1
            BYTE_ORDER=LITTLE_ENDIAN
    )

    target_compile_definitions(${target} PUBLIC KERBAL_TYPE_TRAITS_DEBUG_WARNING=1)

    target_link_libraries(${target} PUBLIC Kerbal::kerbal)

    # test/include
    if (
        (ktest_category STREQUAL "instantiation") OR
        (ktest_category STREQUAL "utest")
    )
        target_include_directories(${target} PUBLIC "${PROJECT_SOURCE_DIR}/include")
    endif ()


    # libc++
    if (KTEST_USE_LIBCXX)
        target_compile_options(${target} PUBLIC -stdlib=libc++)
        if (ktest_category STREQUAL "bench" OR ktest_category STREQUAL "utest")
            target_link_libraries(
                    ${target} PUBLIC
                    ${KTEST_LIB_CPP}
                    ${KTEST_LIB_CPPABI}
            )
        endif ()
    endif ()


    # sanitize
    if (KTEST_ENABLE_SANITIZE)
        if (ktest_category STREQUAL "bench" OR ktest_category STREQUAL "utest")
            if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
                target_compile_options(${target} PUBLIC /fsanitize=address)
            else ()
                target_compile_options(
                        ${target} PUBLIC
                        -fsanitize=address
                        -fsanitize=undefined
                )
                target_link_libraries(
                        ${target} PUBLIC
                        ${KTEST_LIB_ASAN}
                        ${KTEST_LIB_UBSAN}
                )
            endif ()
        endif ()
    endif ()


    # gcov
    if (KTEST_ENABLE_GCOV)
        target_compile_options(${target} PUBLIC --coverage)
        if (ktest_category STREQUAL "bench" OR ktest_category STREQUAL "utest")
            target_link_options(${target} PUBLIC --coverage)
        endif ()
    endif ()


    # wasm
    if (CMAKE_SYSTEM_NAME MATCHES Emscripten)
        target_compile_options(${target} PUBLIC -fexceptions)
        if (ktest_category STREQUAL "bench" OR ktest_category STREQUAL "utest")
            target_link_options(${target} PUBLIC -sALLOW_MEMORY_GROWTH)
            target_link_options(${target} PUBLIC -fexceptions)
        endif ()
    endif ()

endfunction()


# precompile header

option(KTEST_ENABLE_PRECOMPILE_HEADER "enable precompile header" OFF)

if (KTEST_ENABLE_PRECOMPILE_HEADER)
    file(WRITE "${CMAKE_BINARY_DIR}/ktest_precompile_header.cpp" "")
    add_library(ktest_precompile_header OBJECT "${CMAKE_BINARY_DIR}/ktest_precompile_header.cpp")
    ktest_basic_configuration(ktest_precompile_header)
    target_precompile_headers(ktest_precompile_header PUBLIC "${Kerbal_PUBLIC_HEADERS_kerbal}")
endif ()


# ctest
enable_testing()


add_subdirectory(benchmark)
add_subdirectory(instantiation)
add_subdirectory(test)

if (NOT TARGET inst)
    add_custom_target(inst)
endif ()
if (NOT TARGET utest)
    add_custom_target(utest)
endif ()
add_custom_target(
        ktest
        DEPENDS inst utest
)
