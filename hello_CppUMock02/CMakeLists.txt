# (1) CMake definitions, compiler flags and useful variables
cmake_minimum_required(VERSION 3.5)
project(hello_CppUTest)

# add_compile_options(-Wall -Werror)

set(APP_LIB_NAME fooAppLib02)

# (2) Include application build instructions
add_subdirectory(src)

# (3) include tests build instructions
option(COMPILE_TESTS "Compile the tests" ON)
if(COMPILE_TESTS)
    add_subdirectory(tests)
endif(COMPILE_TESTS)

