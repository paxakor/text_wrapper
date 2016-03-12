set(SOURCES
    src/config.c
    src/main.c
    src/utils.c
    )

set(HEADERS
    src/config.h
    src/help.h
    src/utils.h
    )

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Ofast")

add_executable(wrp ${SOURCES})
