//
// Created by etien on 26/09/2021.
//

#include "TextureGraphics.h"

const AsciiSprite *TextureGraphics::GetCurrentFrame() {
    currentAscii = textureSprite.GetAsciiArt();
    return &currentAscii;
}

float TextureGraphics::GetRotation() {
    return textureSprite.GetRotation();
}

void TextureGraphics::SetRotation(float rotation) {
    textureSprite.SetRotation(rotation);
}

TextureGraphics::TextureGraphics(const std::string& filename, IGraphics::Layer layer) : textureSprite(filename) {
    SetLayer(layer);
}
