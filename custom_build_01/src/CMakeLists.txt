set(LIB_SOURCE
        target.cpp
        )

add_library(${LIB_NAME}
        ${LIB_SOURCE})

set(INCLUDE_DIR ../include)

target_include_directories(${LIB_NAME}
        PUBLIC ${INCLUDE_DIR}
)
