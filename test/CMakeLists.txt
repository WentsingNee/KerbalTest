set(EXECUTABLE_OUTPUT_PATH ./test_suites)


macro(add_kerbal_test_target target target_src_file)
    add_executable(${target} ${target_src_file})
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/targets)
    target_include_directories(${target} PUBLIC ./)
    if (KERBAL_TEST_USE_LIBCXX)
        target_compile_options(${target} PUBLIC -stdlib=libc++)
        target_link_libraries(${target} PUBLIC ${LIB_CPP})
        target_link_libraries(${target} PUBLIC ${LIB_CPPABI})
    endif ()
    if (KERBAL_TEST_ENABLE_SANITIZE)
        target_compile_options(${target} PUBLIC -fsanitize=address)
        target_compile_options(${target} PUBLIC -fsanitize=undefined)
        target_link_libraries(${target} PUBLIC ${LIB_ASAN})
        target_link_libraries(${target} PUBLIC ${LIB_UBSAN})
    endif ()
    set(test_targets ${test_targets} ${target})
endmacro()

function(add_kerbal_sub_lib sublib)
    message("add sublib: ${sublib}")
    aux_source_directory(./${sublib} files)
    foreach (file ${files})
        string(REGEX MATCH "./${sublib}/(.+)\\.test\\.cpp$" _ ${file})
        if (CMAKE_MATCH_1)
            set(target test.${sublib}.${CMAKE_MATCH_1})
            message("	add: ${target}  <=  ${file}")
            add_kerbal_test_target(${target} ${file})
            set(test_targets ${test_targets} PARENT_SCOPE)
        else ()
            message(WARNING "   ${file} has been ignored")
        endif ()
    endforeach ()
    message("")
endfunction()


add_kerbal_sub_lib(algorithm)
add_subdirectory(./algorithm)
add_kerbal_sub_lib(any)
add_kerbal_sub_lib(autonm)
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


set(test_targets_count 0)
foreach (target ${test_targets})
    message("test-target ${test_targets_count}: ${target}")
    math(EXPR test_targets_count "${test_targets_count} + 1")
endforeach ()
message("test targets: ${test_targets_count}")
message("\n")


add_custom_target(run_test_targets
        COMMAND
        echo ${PROJECT_BINARY_DIR}/targets\;
        for e in $$\(ls ${PROJECT_BINARY_DIR}/targets/*\)\;
        do
            $$e\;
        done\;
)