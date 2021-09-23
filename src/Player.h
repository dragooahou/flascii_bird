#pragma once

#include "InputManager.h"
#include "NYTimer.h"
#include "GameObject.h"

class Player : public GameObject {

public:

	Player();
	Player(Vector2 position, Graphics gfx);

	void Update(const InputManager& inputManager, NYTimer& timer);

private:

	static constexpr float gravity = 0.0980f;
	static constexpr float jumpForce = 0.8f;
	static constexpr float velocityCap = 0.8f;
	float acceleration;
	float velocity;
};