cmake_minimum_required(VERSION 3.12)

set(APP_SOURCE
        main.cpp
        target.c
        )

set(LOCAL_INCLUDE ../include)

add_executable(${APP_NAME}
        ${APP_SOURCE}
        )

target_include_directories(${APP_NAME}
        PRIVATE ${LOCAL_INCLUDE}
        )

#target_compile_options(${APP_NAME}
#        PUBLIC ${CMAKE_CXX_FLAGS}
#        )

target_link_libraries(${APP_NAME}
        ${LIB_NAME}
        )

