#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Timer.h"

#include "Player.h"
#include "GameManager.h"

/*
Creates a player instance
*/
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
		velocity -= JUMP_FORCE;
		acceleration -= JUMP_FORCE/3;

	}

	float initialVelocity = velocity;

	acceleration += GRAVITY;

	// According to Newton, this might be the right formula
	velocity = initialVelocity + (acceleration * Timer::GetInstance().GetElapsedSeconds(true));

	// Applies a velocity cap to mimic air resistance
	if (velocity >= VELOCITY_CAP) {
		velocity = VELOCITY_CAP;
	}
	else if (velocity <= -VELOCITY_CAP) {
		velocity = -VELOCITY_CAP;
	}

	Vector2 velocityVector = Vector2(0.f, velocity);
	Vector2 pos = GetPosition();

    float angle = (velocityVector + Vector2(1.f, 0.f)).AngleDeg();
    GetGfx()->SetRotation(angle);

    SetPosition(pos + velocityVector);

    // Lose when player touch on the ground
    if(GetPosition().y > GameManager::SCREEN_HEIGHT) {
        GameManager::GetInstance().LoadScene(2);
    }

    collider.position = GetPosition() - collider.size/2.f;

}

const Colliders::ICollider *Player::GetCollider() const {
	return &collider;
}
