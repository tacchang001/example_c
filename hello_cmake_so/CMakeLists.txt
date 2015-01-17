cmake_minimum_required(VERSION 2.8)

set (CMAKE_VERBOSE_MAKEFILE 1)

project (hello C)
set (serial "1.0.0")
set (soserial "1")

set (CMAKE_BUILD_TYPE Debug)

set (TARGET_NAME libhello)
set (SRCS
    src/hello.c
)
set (INCLUDES
    include
)
include_directories (${INCLUDES})
set (CMAKE_C_FLAGS_RELEASE "-Wall -O2")
set (CMAKE_C_FLAGS_DEBUG "-g")
add_library (${TARGET_NAME} SHARED 
    ${SRCS}
)
set_target_properties (${TARGET_NAME} PROPERTIES 
    PREFIX ""
    VERSION ${serial} SOVERSION ${soserial})
