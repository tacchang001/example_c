# (1) Look for installed version of CppUTest
find_package(PkgConfig REQUIRED)
pkg_search_module(CPPUTEST REQUIRED cpputest>=3.8)
message(STATUS "Found CppUTest version ${CPPUTEST_VERSION}")

# (2) Our unit tests sources
set(TEST_APP_NAME ${APP_LIB_NAME}_tests)
set(TEST_SOURCES
        test_target.cpp
        statvfs-mock.c
        )

add_compile_options(
        -Wall -Wno-unused-function
        )

# (3) Take care of include directories
include_directories(${CPPUTEST_INCLUDE_DIRS}
        ../include
        )
link_directories(${CPPUTEST_LIBRARIES})

# (4) Build the unit tests objects and link then with the app library
add_executable(${TEST_APP_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_APP_NAME} ${APP_LIB_NAME} ${CPPUTEST_LDFLAGS})

# (5) Run the test once the build is done
add_custom_command(TARGET ${TEST_APP_NAME} COMMAND ./${TEST_APP_NAME} POST_BUILD)
