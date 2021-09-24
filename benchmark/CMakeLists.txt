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

function(add_kerbal_sub_lib sublib)
    message("add sublib: ${sublib}")
    set(sublib_targets)
    aux_source_directory(./${sublib}/ files)
    foreach(file ${files})
        string(REGEX MATCH "(//)(.+)\\.bench\\.cpp$" _ ${file})
        set(suite_name ${CMAKE_MATCH_2})
        if(suite_name)
            set(target bench.${sublib}.${suite_name})
            set(src_file ${sublib}/${suite_name}.bench.cpp)
            message("	add: ${target} <= ${src_file}")
            add_executable(${target} ./${src_file})
            set(sublib_targets ${sublib_targets} ${target})
        else()
            message(WARNING "   ${file} has been ignored")
        endif()
    endforeach()
    set(targets ${targets} ${sublib_targets} PARENT_SCOPE)
    message("")
endfunction()

add_kerbal_sub_lib(container)
#add_kerbal_sub_lib(./ompalgo)

message("\n")

foreach (target ${targets})
    message("target: " ${target})
endforeach ()

message("\n")
