#pragma once

#include "GameObject.h"

class Obstacle : public GameObject {

    Colliders::Compound collider;

private:
	float fallingSpeed = -0.3f;
	float offset = 26.f;

public:

	static constexpr float scrollingSpeed = 2.f;


	Obstacle();
	Obstacle(Vector2 position, GfxPtr gfx);

	bool isAlreadyChecked = false;

	void Update(float screenWidth, float screenHeight);

    const Colliders::ICollider *GetCollider() const override;
};