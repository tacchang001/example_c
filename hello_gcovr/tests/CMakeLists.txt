find_package(PkgConfig REQUIRED)
pkg_search_module(CPPUTEST REQUIRED cpputest>=3.8)
message(STATUS "Found CppUTest version ${CPPUTEST_VERSION}")

set(TEST_APP_NAME ${APP_LIB_NAME}_tests)
set(TEST_SOURCES
        test_target.cpp
        )

add_compile_options(
        -Wall -Wno-unused-function
        )

include_directories(${CPPUTEST_INCLUDE_DIRS}
        ../include
        )
link_directories(${CPPUTEST_LIBRARIES})

add_executable(${TEST_APP_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_APP_NAME} ${APP_LIB_NAME} ${CPPUTEST_LDFLAGS})

add_custom_command(TARGET ${TEST_APP_NAME} COMMAND ./${TEST_APP_NAME} POST_BUILD)
