cmake_minimum_required(VERSION 3.20)
project(projet_ascii)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        src/main.cpp
        src/utils.cpp       src/utils.h
        src/GameObject.cpp  src/GameObject.h
        src/Sprite.cpp      src/Sprite.h
        src/Graphics.cpp    src/Graphics.h
        src/Vector2.cpp     src/Vector2.h)
        

add_executable(projet_ascii ${SOURCES})
