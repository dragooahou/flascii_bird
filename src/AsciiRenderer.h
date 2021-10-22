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

    using ScreenBuffer = CHAR_INFO[HEIGHT][WIDTH];

    ScreenBuffer buffers[static_cast<int>(SimpleGraphics::Layer::count)];
    bool showColliders = false;

public:
    AsciiRenderer();

    void Clear();
    void Render(const GameObject& gameObject);
    void Present();

    void SetShowColliders(bool showColliders);
    bool IsShowColliders() const;
};


template<int WIDTH, int HEIGHT>
AsciiRenderer<WIDTH, HEIGHT>::AsciiRenderer() {

}

template<int WIDTH, int HEIGHT>
void AsciiRenderer<WIDTH, HEIGHT>::Clear() {

    for(int i = 0; i < static_cast<int>(SimpleGraphics::Layer::count); ++i) {
        for(int y = 0; y < HEIGHT; ++y) {
            for(int x = 0; x < WIDTH; ++x) {
                buffers[i][y][x].Char.AsciiChar = ' ';
                buffers[i][y][x].Attributes = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE;
            }
        }
    }
}

template<int WIDTH, int HEIGHT>
void AsciiRenderer<WIDTH, HEIGHT>::Present() {

    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
    static const COORD dwBufferSize = {WIDTH,HEIGHT};
    static const COORD dwBufferCoord = { 0, 0 };
    static SMALL_RECT rcRegion = { 0, 0, WIDTH-1, HEIGHT-1 };


    ScreenBuffer finalBuffer;
    memcpy(finalBuffer, buffers, WIDTH * HEIGHT * sizeof(CHAR_INFO));

    for(int i = 1; i < static_cast<int>(SimpleGraphics::Layer::count); ++i) {
        utils::memcpy_if<CHAR_INFO>((CHAR_INFO *)finalBuffer, (CHAR_INFO *)buffers[i], WIDTH * HEIGHT,
             [](CHAR_INFO c) {
                 return c.Char.AsciiChar != ' ';
             });
    }

    if(!WriteConsoleOutput( hOutput, (CHAR_INFO *)finalBuffer, dwBufferSize, dwBufferCoord, &rcRegion)) {
        std::cout << "SetConsoleWindowInfo() error:  " << utils::GetLastErrorAsString() << std::endl;
    }

}

template<int WIDTH, int HEIGHT>
void AsciiRenderer<WIDTH, HEIGHT>::Render(const GameObject &gameObject) {

    const AsciiSprite* spriteToRender = gameObject.GetGfx()->GetCurrentFrame();
    const Vector2& goPosition = gameObject.GetPosition();
    const int height = spriteToRender->GetHeight();
    const int width = spriteToRender->GetWidth();
    const Vector2 spriteCenterOffset = spriteToRender->GetCenterOffset();

    for(int y = 0; y < height; ++y) {
        for(int x = 0; x < width; ++x) {

            int yPos = static_cast<int>(goPosition.y) + y - static_cast<int>(spriteCenterOffset.y);
            int xPos = static_cast<int>(goPosition.x) + x - static_cast<int>(spriteCenterOffset.x);

            CHAR_INFO c = spriteToRender->GetAsciiArt()(y, x);

            // Filter pixels that are outside the screen or spaces
            if(xPos >= WIDTH || xPos < 0 || yPos >= HEIGHT || yPos < 0 || c.Char.AsciiChar == ' ') {
                continue;
            }

            buffers[static_cast<int>(gameObject.GetGfx()->GetLayer())][yPos][xPos] = c;

        }
    }

    if(showColliders) {

        const auto* collider = gameObject.GetCollider();

        for(int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                if(collider != nullptr) {
                    if(collider->CollideWith(Vector2(x, y))) {
                        buffers[static_cast<int>(gameObject.GetGfx()->GetLayer())][y][x].Attributes = BACKGROUND_GREEN;
                        buffers[static_cast<int>(SimpleGraphics::Layer::BACKGROUND)][y][x].Attributes = BACKGROUND_GREEN;
                    }
                }
            }
        }

    }

}

template<int WIDTH, int HEIGHT>
void AsciiRenderer<WIDTH, HEIGHT>::SetShowColliders(bool showColliders) {
    AsciiRenderer::showColliders = showColliders;
}

template<int WIDTH, int HEIGHT>
bool AsciiRenderer<WIDTH, HEIGHT>::IsShowColliders() const {
    return showColliders;
}


#endif //PROJET_ASCII_ASCIIRENDERER_H
