cmake_minimum_required(VERSION 3.10)
project(KerbalTest CXX)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Platform: ${CMAKE_CXX_PLATFORM_ID}")
message(STATUS "ARCHITECTURE: ${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_HOST_SYSTEM_PROCESSOR: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_TARGET_SYSTEM_PROCESSOR: ${CMAKE_TARGET_SYSTEM_PROCESSOR}")


if (NOT TARGET Kerbal::kerbal)
    message(STATUS "Finding Kerbal")
    find_package(Kerbal REQUIRED)
    message(STATUS "Finding Kerbal -- found")
endif ()

message(STATUS "Kerbal_VERSION: ${Kerbal_VERSION}")
message(STATUS "Kerbal_INCLUDE_DIRS: ${Kerbal_INCLUDE_DIRS}")

# compiler global configuration

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    add_compile_options(-Wall)
    message(STATUS "CXX flags: -Wall")

    add_compile_options(-Wextra)
    message(STATUS "CXX flags: -Wextra")

    add_compile_options(-Wno-unused-parameter)
    message(STATUS "CXX flags: -Wno-unused-parameter")
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


# precompile header

option(KTEST_ENABLE_PRECOMPILE_HEADER "enable precompile header" OFF)

if (KTEST_ENABLE_PRECOMPILE_HEADER)
    file(WRITE "${CMAKE_BINARY_DIR}/ktest_precompile_header.cpp" "")
    add_library(ktest_precompile_header OBJECT "${CMAKE_BINARY_DIR}/ktest_precompile_header.cpp")
    if (KTEST_USE_LIBCXX)
        target_compile_options(ktest_precompile_header PUBLIC -stdlib=libc++)
        target_link_libraries(ktest_precompile_header PUBLIC ${KTEST_LIB_CPP})
        target_link_libraries(ktest_precompile_header PUBLIC ${KTEST_LIB_CPPABI})
    endif ()
    target_precompile_headers(ktest_precompile_header PUBLIC "${Kerbal_PUBLIC_HEADERS_kerbal}")
    target_link_libraries(ktest_precompile_header PUBLIC Kerbal::kerbal)
endif ()


# ctest
enable_testing()


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
