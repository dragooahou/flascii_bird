#pragma once

#include "GameObject.h"

class Obstacle : public GameObject {

    Colliders::Compound collider;

public:

	static constexpr float scrollingSpeed = 1.f;


	Obstacle();
	Obstacle(Vector2 position, GfxPtr gfx);

	bool isAlreadyChecked = false;

	void Update(float screenWidth, float screenHeight);

    const Colliders::ICollider *GetCollider() const override;
};