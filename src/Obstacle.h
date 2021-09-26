#pragma once

#include "GameObject.h"

class Obstacle : public GameObject {

public:

	static constexpr float scrollingSpeed = 1.f;

	Obstacle();
	Obstacle(Vector2 position, GfxPtr gfx);

	void Update(float screenWidth, float screenHeight);

};