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
        src/Timer.cpp src/Timer.h
        src/Obstacle.cpp            src/Obstacle.h
        src/IGraphics.cpp           src/IGraphics.h
        src/TextureGraphics.cpp     src/TextureGraphics.h
        src/ScoreDisplayer.cpp      src/ScoreDisplayer.h
        src/GameManager.cpp         src/GameManager.h
        src/Colliders.cpp           src/Colliders.h
        src/BackgroundObject.cpp    src/BackgroundObject.h
        src/Scene.cpp               src/Scene.h
        src/TitleScene.cpp          src/TitleScene.h
        src/GameScene.cpp           src/GameScene.h
        src/GameOverScene.cpp       src/GameOverScene.h)
            

add_executable(projet_ascii ${SOURCES})

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(projet_ascii PRIVATE -fsanitize=address /EHa)
    target_link_directories(projet_ascii PRIVATE "$ENV{ProgramFiles\(x86\)}/Microsoft Visual Studio/2019/Professional/VC/Tools/Llvm/x64/lib/clang/10.0.0/lib/windows")
    target_link_libraries(projet_ascii PRIVATE clang_rt.asan_dynamic-x86_64 clang_rt.asan_dynamic_runtime_thunk-x86_64)
    target_link_options(projet_ascii PRIVATE /wholearchive:clang_rt.asan_dynamic_runtime_thunk-x86_64.lib)
endif()