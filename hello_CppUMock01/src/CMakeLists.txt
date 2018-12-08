# (1) Build a library with my application sources
set(APP_LIB_SOURCE
        target.cpp
        )

set(INCLUDE_DIR ../include)

add_library(${APP_LIB_NAME} ${APP_LIB_SOURCE})

target_include_directories(
        ${APP_LIB_NAME}
        PUBLIC ${INCLUDE_DIR}
)
