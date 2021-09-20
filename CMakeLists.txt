cmake_minimum_required(VERSION 3.20)
project(projet_ascii)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        src/main.cpp
        src/utils.cpp src/utils.h)

add_executable(projet_ascii ${SOURCES})
