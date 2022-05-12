set(EXECUTABLE_OUTPUT_PATH ./test_suites)
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
    aux_source_directory(./${sublib} files)
    foreach (file ${files})
        string(REGEX MATCH "./${sublib}/(.+)\\.test\\.cpp$" _ ${file})
        if (CMAKE_MATCH_1)
            set(target test.${sublib}.${CMAKE_MATCH_1})
            message("	add: ${target}  <=  ${file}")
            add_kerbal_test_target(${target} ${file})
            set(sublib_targets ${sublib_targets} ${target})
        else ()
            message(WARNING "   ${file} has been ignored")
        endif ()

    endforeach ()
    set(targets ${targets} ${sublib_targets} PARENT_SCOPE)
    message("")
endfunction()


add_kerbal_sub_lib(algorithm)
add_subdirectory(./algorithm)
add_kerbal_sub_lib(bitset)
add_kerbal_sub_lib(compare)
add_kerbal_sub_lib(compatibility)
add_kerbal_sub_lib(config)
add_kerbal_sub_lib(container)
add_kerbal_sub_lib(function)
add_kerbal_sub_lib(hash)
add_kerbal_sub_lib(iterator)
add_kerbal_sub_lib(memory)
add_kerbal_sub_lib(numeric)
add_kerbal_sub_lib(optional)
add_kerbal_sub_lib(random)
add_kerbal_sub_lib(test)
add_kerbal_sub_lib(type_traits)
add_kerbal_sub_lib(utility)

message("\n")

set(targets_count 0)
foreach (target ${targets})
    message("test-target ${targets_count}: ${target}")
    math(EXPR targets_count "${targets_count} + 1")
endforeach ()

message("\n")


add_custom_target(run_test_targets
        COMMAND
        cd targets\;
        for e in $$\(ls ./*\)\;
        do
            $$e\;
        done\;
)