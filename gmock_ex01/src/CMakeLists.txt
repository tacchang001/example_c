# https://stackoverrun.com/ja/q/11153736
set(LIB_SOURCE
        Foo.cpp
        Bar.cpp
        )

set(INCLUDE_DIR ../include)

add_library(${LIB_NAME} ${LIB_SOURCE})

target_include_directories(
        ${LIB_NAME}
        PUBLIC ${INCLUDE_DIR}
)

add_compile_options(
        -std=gnu++14 -Wall -Wno-unused-function
)
