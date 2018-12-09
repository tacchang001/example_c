cmake_minimum_required(VERSION 3.12)

project(custom_build_01)
    message(STATUS "set project")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake_modules)
include (gcovr)
include (debug_print_values)
    print_project_values()

set(LIB_NAME helloLib01)

add_compile_options(-std=c++14 -Wall -Werror)
    print_compile_values()

add_subdirectory(src)

option(COMPILE_TESTS "Compile the tests" ON)
if(COMPILE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif(COMPILE_TESTS)


