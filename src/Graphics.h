#pragma once

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
	Sprite* sprites;
	float speed;
	int currentFrame;
	Layer layer;

};


