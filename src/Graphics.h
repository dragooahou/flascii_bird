#pragma once

#include <vector>

#include "AsciiSprite.h"

class Graphics {

public:
	enum class Layer {

		BACKGROUND,
		OBJECTS,
		VFX,
		UI,

        count
	};

private:
	std::vector<AsciiSprite*> sprites;
	float speed = 1;
	int currentFrame = 0;
	Layer layer = Layer::OBJECTS;

public:

    Graphics() = default;
    Graphics(const std::vector<AsciiSprite*> &sprites, Layer layer);

    const std::vector<AsciiSprite*> &GetSprites() const;

    float GetSpeed() const;

    int GetCurrentFrameID() const;
    const AsciiSprite* GetCurrentFrame() const;

    Layer GetLayer() const;

    void SetSpeed(float speed);

    void SetCurrentFrame(int currentFrame);

    void SetLayer(Layer layer);

};


