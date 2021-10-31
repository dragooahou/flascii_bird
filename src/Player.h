#pragma once

#include "InputManager.h"
#include "GameObject.h"

class Player : public GameObject {

    Colliders::Rectangle collider;

public:

	Player() = default;
	Player(Vector2 position, GfxPtr gfx);

	void Update() override;

    const Colliders::ICollider *GetCollider() const override;

private:

	int score = 0;
	static constexpr float GRAVITY = 0.3f;
	static constexpr float JUMP_FORCE = 3.f;
	static constexpr float VELOCITY_CAP = 1.1f;
	float acceleration;
	float velocity;

};