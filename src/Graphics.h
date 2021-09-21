#pragma once

#include <vector>

#include "Sprite.h"

class Graphics {

public:
	enum class Layer {

		BACKGROUND = 0,
		OBJECTS = 1,
		VFX = 2,
		UI = 3

	};

private:
	std::vector<Sprite> sprites;
	float speed = 1;
	int currentFrame = 0;
	Layer layer = Layer::OBJECTS;

public:

    Graphics() = default;
    Graphics(const std::vector<Sprite> &sprites, Layer layer);

    const std::vector<Sprite> &GetSprites() const;

    float GetSpeed() const;

    int GetCurrentFrameID() const;
    const Sprite& GetCurrentFrame() const;

    Layer GetLayer() const;

    void SetSpeed(float speed);

    void SetCurrentFrame(int currentFrame);

    void SetLayer(Layer layer);

};


