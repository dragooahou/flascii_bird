#pragma once

#include "InputManager.h"
#include "GameObject.h"

class Player : public GameObject {

    Colliders::Rectangle collider;

public:

	Player();
	Player(Vector2 position, GfxPtr gfx);

	void Update(const InputManager& inputManager, NYTimer& timer);

    const Colliders::ICollider *GetCollider() const override;

private:

	static constexpr float gravity = 0.0980f;
	static constexpr float jumpForce = 0.8f;
	static constexpr float velocityCap = 0.8f;
	float acceleration;
	float velocity;
};