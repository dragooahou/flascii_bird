#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "NYTimer.h"

#include "Player.h"


Player::Player(Vector2 position, Graphics gfx)
{
	SetPosition(position);
	SetGfx(gfx);
	acceleration = 0.f;
	velocity = 0.f;
}

void Player::Update(const InputManager& inputManager, NYTimer& timer) {

	if (inputManager.getVirtualKeyState(VK_SPACE) == InputManager::Input::JUST_PRESSED) {

		acceleration = 0.f;
		velocity = 0.f;
		velocity -= jumpForce;
		acceleration += jumpForce;

	}

	float initialVelocity = velocity;

	acceleration += gravity;


	velocity = initialVelocity + (acceleration * timer.getElapsedSeconds(true));

	if (velocity >= velocityCap) {
		velocity = velocityCap;
	}
	else if (velocity <= -velocityCap) {
		velocity = -velocityCap;
	}

	const Vector2 velocityVector = Vector2(0.f, velocity);
	Vector2 pos = GetPosition();

	SetPosition(pos + velocityVector);

}