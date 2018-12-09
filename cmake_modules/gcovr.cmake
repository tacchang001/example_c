# https://micsop.com/2018/03/16/code-coverage-with-gcov-and-cmake/
if(USE_GCOV)
    SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

    SET(GCC_COVERAGE_LINK_FLAGS "-lgcov")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

#[[    add_custom_command(OUTPUT _run_gcovr_parser
            POST_BUILD
            COMMAND ${GCOVR} -r ${CMAKE_SOURCE_DIR}/src --object-dir=
            ${CMAKE_BINARY_DIR} -e test_*
            COMMAND ${GCOVR} -r ${CMAKE_SOURCE_DIR}/src --object-dir=
            ${CMAKE_BINARY_DIR} --branches --exclude-unreachable-branches -e test_*
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    add_custom_target (coverage DEPENDS _run_gcovr_parser)]]
endif(USE_GCOV)
