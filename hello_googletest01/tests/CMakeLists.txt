find_package(PkgConfig)
pkg_check_modules(GTEST gtest>=1.7.0 REQUIRED)
pkg_check_modules(GMOCK gmock>=1.7.0 REQUIRED)

set(TEST_APP_NAME ${LIB_NAME}_tests)
set(TEST_SOURCES
        test_target.cpp
        )

add_compile_options(
        -std=gnu++11 -Wall -Wno-unused-function
)

include_directories(${CPPUTEST_INCLUDE_DIRS}
        ../include
        )

link_directories(${GTEST_LIBRARIES})

add_executable(${TEST_APP_NAME} ${TEST_SOURCES})

target_link_libraries(${TEST_APP_NAME} ${LIB_NAME} ${GTEST_LDFLAGS} gtest_main)

add_custom_command(TARGET ${TEST_APP_NAME}
        COMMAND ./${TEST_APP_NAME}
        COMMAND /home/devel/.local/bin/gcovr
        --root ${CMAKE_SOURCE_DIR}
        --exclude-directories="cmake-build-debug/hello_gcovr/tests"
        --html --html-detail
        --output coverage.html
        POST_BUILD
        )
