//
// Created by etien on 21/09/2021.
//

#ifndef PROJET_ASCII_ASCIIRENDERER_H
#define PROJET_ASCII_ASCIIRENDERER_H


#include <windows.h>
#include <iostream>
#include "GameObject.h"
#include "utils.h"

template<int WIDTH, int HEIGHT>
class AsciiRenderer {

    CHAR_INFO screenBuffer[HEIGHT][WIDTH];

public:
    AsciiRenderer();

    void Clear();
    void Render(const GameObject& gameObject);
    void Present();


};


template<int WIDTH, int HEIGHT>
AsciiRenderer<WIDTH, HEIGHT>::AsciiRenderer() {

}

template<int WIDTH, int HEIGHT>
void AsciiRenderer<WIDTH, HEIGHT>::Clear() {

    for(int y = 0; y < HEIGHT; ++y) {
        for(int x = 0; x < WIDTH; ++x) {
            screenBuffer[y][x].Char.AsciiChar = ' ';
            screenBuffer[y][x].Attributes = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE;
        }
    }

}

template<int WIDTH, int HEIGHT>
void AsciiRenderer<WIDTH, HEIGHT>::Present() {

    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
    static const COORD dwBufferSize = {WIDTH,HEIGHT};
    static const COORD dwBufferCoord = { 0, 0 };
    static SMALL_RECT rcRegion = { 0, 0, WIDTH-1, HEIGHT-1 };

    if(!WriteConsoleOutput( hOutput, (CHAR_INFO *)screenBuffer, dwBufferSize, dwBufferCoord, &rcRegion)) {
        std::cout << "SetConsoleWindowInfo() error:  " << utils::GetLastErrorAsString() << std::endl;
    }

}

template<int WIDTH, int HEIGHT>
void AsciiRenderer<WIDTH, HEIGHT>::Render(const GameObject &gameObject) {

    const Sprite* spriteToRender = gameObject.GetGfx().GetCurrentFrame();
    const Vector2& goPosition = gameObject.GetPosition();
    const int height = spriteToRender->GetHeight();
    const int width = spriteToRender->GetWidth();

    for(int y = 0; y < height; ++y) {
        for(int x = 0; x < width; ++x) {
            screenBuffer[static_cast<int>(goPosition.y) + y]
                        [static_cast<int>(goPosition.x) + x]
                        .Char.AsciiChar = spriteToRender->GetAsciiArt()[y][x];
        }
    }

}


#endif //PROJET_ASCII_ASCIIRENDERER_H
