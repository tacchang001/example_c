cmake_minimum_required(VERSION 2.8)

set (CMAKE_VERBOSE_MAKEFILE 1)

project (hello C)

set (CMAKE_BUILD_TYPE Debug)

set (CMAKE_C_FLAGS "-Wall -Werror")

set (TARGET_EXE_NAME example)
set (SRCS
    src/main.c
)
include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/../hello_cmake_so/include
)
link_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/../hello_cmake_so/build
)
set (LIBS
    hello
)

add_executable (${TARGET_EXE_NAME}
    ${SRCS}
)
target_link_libraries (${TARGET_EXE_NAME} ${LIBS})

#set (CMAKE_ECLIPSE_VERSION Kepler)
