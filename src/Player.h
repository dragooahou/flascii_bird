#pragma once

#include "InputManager.h"
#include "GameObject.h"

class Player : public GameObject {

    Colliders::Rectangle collider;

public:

	Player();
	Player(Vector2 position, GfxPtr gfx);

	void Update() override;

    const Colliders::ICollider *GetCollider() const override;

private:

	int score = 0;
	static constexpr float gravity = 0.3f;
	static constexpr float jumpForce = 3.f;
	static constexpr float velocityCap = 1.1f;
	float acceleration;
	float velocity;
};