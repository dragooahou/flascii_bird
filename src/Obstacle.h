#pragma once

#include "GameObject.h"

class Obstacle : GameObject {

public:

	static constexpr float scrollingSpeed = 1.f;

	Obstacle();
	Obstacle(Vector2 position, Graphics gfx);

	void Update(float screenWidth, float screenHeight);

};