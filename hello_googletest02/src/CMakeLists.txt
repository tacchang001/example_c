# (1) Build a library with my application sources
set(LIB_SOURCE
        target.cpp
        )

set(INCLUDE_DIR ../include)

add_library(${LIB_NAME} ${LIB_SOURCE})

target_include_directories(
        ${LIB_NAME}
        PUBLIC ${INCLUDE_DIR}
)
