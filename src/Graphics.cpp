
#include <vector>
#include "Graphics.h"

const std::vector <Sprite> &Graphics::GetSprites() const {
    return sprites;
}

float Graphics::GetSpeed() const {
    return speed;
}

int Graphics::GetCurrentFrameID() const {
    return currentFrame;
}

Graphics::Layer Graphics::GetLayer() const {
    return layer;
}

const Sprite &Graphics::GetCurrentFrame() const {
    return sprites[currentFrame];
}

void Graphics::SetSpeed(float speed) {
    Graphics::speed = speed;
}

void Graphics::SetCurrentFrame(int currentFrame) {
    Graphics::currentFrame = currentFrame;
}

void Graphics::SetLayer(Graphics::Layer layer) {
    Graphics::layer = layer;
}

Graphics::Graphics(const std::vector<Sprite> &sprites, Graphics::Layer layer) : sprites(sprites), layer(layer) {}
