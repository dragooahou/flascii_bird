#include "BackgroundObject.h"
#include "GameObject.h"
#include  "GameManager.h"

#define OUT_OF_SCREEN_OFFSET 10
#define RANDOM_ADDED_OFFSET 60


float BackgroundObject::GetDepth() {
	return depth;
}


/*
A scrolling GameObject with a depth value used for parallax
*/
BackgroundObject::BackgroundObject(float depth, const Vector2& position, GfxPtr gfx) : GameObject(position, gfx), depth(depth) {}


/*
Scrolling according to depth value
*/
void BackgroundObject::Update() {
	if (GetPosition().x <= -20) {
		SetPosition({ GameManager::SCREEN_WIDTH + OUT_OF_SCREEN_OFFSET + (rand() / (float)RAND_MAX) * RANDOM_ADDED_OFFSET, (rand() / (float)RAND_MAX) * GameManager::SCREEN_HEIGHT });
	}
	SetPosition({ GetPosition().x -(SPEED / (depth+2)), GetPosition().y });
}


