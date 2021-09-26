//
// Created by etien on 26/09/2021.
//

#ifndef PROJET_ASCII_TEXTUREGRAPHICS_H
#define PROJET_ASCII_TEXTUREGRAPHICS_H


#include "IGraphics.h"
#include "TextureSprite.h"

class TextureGraphics : public IGraphics {

    TextureSprite textureSprite;

    AsciiSprite currentAscii;

public:
    TextureGraphics(const std::string& filename, IGraphics::Layer layer);

    const AsciiSprite *GetCurrentFrame() override;

    float GetRotation() override;
    void SetRotation(float rotation) override;

};


#endif //PROJET_ASCII_TEXTUREGRAPHICS_H
