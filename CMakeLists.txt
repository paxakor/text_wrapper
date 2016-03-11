cmake_minimum_required(VERSION 3.4)
project(text_wrapper)

include_directories("./")

set(SOURCES
    main.c
    config.c
    )

set(HEADERS
    config.h
    utils.h
    help.h
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

if(GIT_BRANCH STREQUAL "master")
    message(STATUS "Release version")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Ofast")
else()
    message(STATUS "Developer version")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb -pg")
endif()

add_executable(wrp ${SOURCES})
