cmake_minimum_required(VERSION 3.0)

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

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")

if(GIT_BRANCH STREQUAL "master")
    message(STATUS "Release version")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast -Werror")
else()
    message(STATUS "Developer version")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb -pg")
endif()

add_executable(wrp ${SOURCES})
