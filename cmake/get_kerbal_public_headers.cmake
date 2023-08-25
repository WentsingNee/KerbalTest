#
# @file       get_kerbal_public_headers.cmake
# @brief
# @date       2023-08-25
# @author     Peter
# @copyright
#      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
#   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
#   all rights reserved
#

function(get_kerbal_public_headers KERBAL_INCLUDE_DIRECTORY _OUTPUT_LIST_NAME)
    if (NOT EXISTS ${KERBAL_INCLUDE_DIRECTORY})
        message(WARNING "KERBAL_INCLUDE_DIRECTORY is not found. \nKERBAL_INCLUDE_DIRECTORY: ${KERBAL_INCLUDE_DIRECTORY}")
    endif ()

    file(GLOB_RECURSE kerbal_header_files RELATIVE "${KERBAL_INCLUDE_DIRECTORY}/" "${KERBAL_INCLUDE_DIRECTORY}/*.hpp")

    set(kerbal_public_headers)

    set(block_patterns
            ".*part\.hpp$"
            "^kerbal/openmp/*"
    )

    foreach (file ${kerbal_header_files})

        set(block FALSE)
        foreach (block_pattern ${block_patterns})
            string(REGEX MATCH ${block_pattern} _ ${file})
            if (CMAKE_MATCH_0)
#                message(WARNING "   ${file} has been ignored")
                set(block TRUE)
                break()
            endif ()
        endforeach ()

        if (NOT ${block})
            list(APPEND kerbal_public_headers "${file}")
        endif ()
    endforeach ()

    list(LENGTH kerbal_public_headers kerbal_public_header_len)
    if (kerbal_public_header_len EQUAL 0)
        message(WARNING "kerbal public header is empty")
    endif ()

    set(${_OUTPUT_LIST_NAME} ${kerbal_public_headers} PARENT_SCOPE)
endfunction()
