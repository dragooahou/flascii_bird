#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Timer.h"

#include "Player.h"


Player::Player() {

}

Player::Player(Vector2 position, GfxPtr gfx) : GameObject(position, gfx)
{
	acceleration = 0.f;
	velocity = 0.f;
    collider.size = Vector2(18, 8);
}

void Player::Update() {

	if (InputManager::GetInstance().getVirtualKeyState(VK_SPACE) == InputManager::Input::JUST_PRESSED) {

		acceleration = 0.f;
		velocity = 0.f;
		velocity -= jumpForce;
		acceleration -= jumpForce/3;

	}

	float initialVelocity = velocity;

	acceleration += gravity;


	velocity = initialVelocity + (acceleration * Timer::GetInstance().GetElapsedSeconds(true));

	if (velocity >= velocityCap) {
		velocity = velocityCap;
	}
	else if (velocity <= -velocityCap) {
		velocity = -velocityCap;
	}

	Vector2 velocityVector = Vector2(0.f, velocity);
	Vector2 pos = GetPosition();

    float angle = (velocityVector + Vector2(1.f, 0.f)).AngleDeg();
    GetGfx()->SetRotation(angle);

    SetPosition(pos + velocityVector);

    collider.position = GetPosition() - collider.size/2.f;

}

const Colliders::ICollider *Player::GetCollider() const {
    return &collider;
}
