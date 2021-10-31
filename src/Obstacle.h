#pragma once

#include "GameObject.h"
#include "Player.h"

class Obstacle : public GameObject {

    Colliders::Compound collider;

private:

	static constexpr float FALLING_SPEED = -0.3f;
	static constexpr float FALLING_OFFSET = 26.f;
	static constexpr float SCROLLING_SPEED = 2.f;

public:

	Player* player;
	Obstacle() = default;
	Obstacle(Player* player, Vector2 position, GfxPtr gfx);

	bool isBehindPlayer = false;

	void Update() override;

    const Colliders::ICollider *GetCollider() const override;
};