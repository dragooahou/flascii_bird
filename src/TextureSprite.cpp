#include "TextureSprite.h"

#include <iostream>
#include <fstream>

const char *ASCII_LIST = "@#%xo;:,. ";

using namespace cimg_library;

void InitCImg() {
    cimg_library::cimg::imagemagick_path("ImageMagick-7.1.0-portable-Q8-x86\\magick.exe");
}

CImg<> rgb2gray(CImg<> color_img) {
    // create a gray image
    CImg<> gray_img(color_img.width(), color_img.height(), 1, 1, 0);

    // for all pixels x,y in image
    cimg_forXY(color_img, x, y) {
        // separation of channels
        int R = (int) color_img(x, y, 0, 0);
        int G = (int) color_img(x, y, 0, 1);
        int B = (int) color_img(x, y, 0, 2);

        // calculate gray value
        // (x, y) -> val_a,   (x, y) -> a, b, c
        int gray_val = (int) (0.299 * R + 0.587 * G + 0.114 * B);
        gray_img(x, y, 0, 0) = gray_val;
    }
    gray_img.normalize(0, 9);
    return gray_img;
}

TextureSprite::TextureSprite(const std::string &filename) : originalImg(filename.c_str()) {
    originalImg = rgb2gray(originalImg);
    rotatedImg = originalImg;
}

AsciiSprite TextureSprite::GetAsciiArt(int div_w, int div_h) const {

    int w = rotatedImg.width() / div_w;
    int h = rotatedImg.height() / div_h;
    auto resizedImg =  rotatedImg.get_resize(w, h);

    auto sprite = AsciiSprite(h, w);

    cimg_forY(resizedImg,y) {
        cimg_forX(resizedImg,x) {
            int val = resizedImg(x, y, 0, 0);
            char c = ASCII_LIST[val];
            sprite.SetChar(x, y, c);
        }
    }

    return sprite;
}

void TextureSprite::Rotate(float degree) {
    rotation += degree;
    rotatedImg = originalImg.get_rotate(rotation, 0, 1);
}

float TextureSprite::GetRotation() const {
    return rotation;
}

void TextureSprite::SetRotation(float degree) {
    if(rotation == degree) {
        return;
    }
    rotation = degree;
    rotatedImg = originalImg.get_rotate(rotation, 0, 1);
}
