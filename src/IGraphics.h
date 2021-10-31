//
// Created by etien on 26/09/2021.
//

#ifndef PROJET_ASCII_IGRAPHICS_H
#define PROJET_ASCII_IGRAPHICS_H


#include "AsciiSprite.h"

class IGraphics {

public:

    enum class Layer {

        BACKGROUND,
        OBJECTS,
        VFX,
        UI,

        count
    };

private:

    Layer layer = Layer::OBJECTS;

public:

    virtual const AsciiSprite* GetCurrentFrame() = 0;

    Layer GetLayer() const;
    void SetLayer(Layer layer);

    virtual float GetRotation();
    virtual void SetRotation(float rotation);


};


#endif //PROJET_ASCII_IGRAPHICS_H
