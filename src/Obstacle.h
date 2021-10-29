#pragma once

#include "GameObject.h"
#include "Player.h"

class Obstacle : public GameObject {

    Colliders::Compound collider;

private:
	float fallingSpeed = -0.3f;
	float offset = 26.f;

public:

	static constexpr float scrollingSpeed = 2.f;

	Player* player;
	Obstacle();
	Obstacle(Player* player, Vector2 position, GfxPtr gfx);

	bool isBehindPlayer = false;

	void Update() override;

    const Colliders::ICollider *GetCollider() const override;
};