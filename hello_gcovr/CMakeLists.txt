cmake_minimum_required(VERSION 3.12)
project(hello_gcovr)

add_compile_options(-std=c++14 -Wall -Werror)

set(APP_LIB_NAME fooAppLib03)

add_subdirectory(src)

option(COMPILE_TESTS "Compile the tests" ON)
if(COMPILE_TESTS)
    add_subdirectory(tests)
endif(COMPILE_TESTS)

