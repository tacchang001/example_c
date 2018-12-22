# https://stackoverrun.com/ja/q/11153736
cmake_minimum_required(VERSION 3.12)
project(hello_GoogleTest01)

set(LIB_NAME fooAppLib)

add_subdirectory(src)

option(COMPILE_TESTS "Compile the tests" ON)
if(COMPILE_TESTS)
    add_subdirectory(tests)
endif(COMPILE_TESTS)

