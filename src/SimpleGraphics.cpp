
#include <vector>
#include "SimpleGraphics.h"

const std::vector <AsciiSprite*> &SimpleGraphics::GetSprites() const {
    return sprites;
}

float SimpleGraphics::GetSpeed() const {
    return speed;
}

int SimpleGraphics::GetCurrentFrameID() const {
    return currentFrame;
}

const AsciiSprite* SimpleGraphics::GetCurrentFrame() {
    return sprites[currentFrame];
}

void SimpleGraphics::SetSpeed(float speed) {
    SimpleGraphics::speed = speed;
}

void SimpleGraphics::SetCurrentFrame(int currentFrame) {
    SimpleGraphics::currentFrame = currentFrame;
}

SimpleGraphics::SimpleGraphics(const std::vector<AsciiSprite*> &sprites, SimpleGraphics::Layer layer) : sprites(sprites) {
    SetLayer(layer);
}
