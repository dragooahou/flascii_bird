#pragma once

#undef cimg_display
#define cimg_display 0              // no need to show image

#include <memory>

#include "CImg.h"
#include "AsciiSprite.h"

void InitCImg();

class TextureSprite {

    cimg_library::CImg<> originalImg;
    cimg_library::CImg<> rotatedImg;

    float rotation = 0.f;

public:
    explicit TextureSprite(const std::string& filename);

    AsciiSprite GetAsciiArt(int div_w = 8, int div_h = 16) const;

    void Rotate(float degree);
    void SetRotation(float degree);

    float GetRotation() const;
};