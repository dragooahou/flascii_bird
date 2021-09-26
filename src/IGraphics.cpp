//
// Created by etien on 26/09/2021.
//

#include "IGraphics.h"

IGraphics::Layer IGraphics::GetLayer() const {
    return layer;
}

void IGraphics::SetLayer(IGraphics::Layer layer) {
    IGraphics::layer = layer;
}

void IGraphics::SetRotation(float rotation) {

}

float IGraphics::GetRotation() {
    return 0;
}
