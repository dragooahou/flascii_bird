cmake_minimum_required(VERSION 3.18)
project(projet_ascii)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        src/main.cpp
        src/utils.cpp               src/utils.h
        src/GameObject.cpp          src/GameObject.h
        src/AsciiSprite.cpp         src/AsciiSprite.h
        src/SimpleGraphics.cpp      src/SimpleGraphics.h
        src/Vector2.cpp             src/Vector2.h
        src/AsciiRenderer.cpp       src/AsciiRenderer.h
        src/InputManager.cpp        src/InputManager.h
        src/TextureSprite.cpp       src/TextureSprite.h
                                    src/Matrix.h
                                    src/CImg.h
        src/Player.cpp	            src/Player.h
        src/NYTimer.cpp		        src/NYTimer.h
        src/Rect.cpp                src/Rect.h
        src/Obstacle.cpp            src/Obstacle.h
        src/IGraphics.cpp           src/IGraphics.h
        src/TextureGraphics.cpp     src/TextureGraphics.h
        src/ScoreDisplayer.cpp      src/ScoreDisplayer.h
        src/GameManager.cpp         src/GameManager.h)

add_executable(projet_ascii ${SOURCES})
target_compile_options(projet_ascii PRIVATE /showIncludes)
