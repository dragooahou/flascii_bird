#include "Obstacle.h"
#include <random>
#include <time.h>
#include "Vector2.h"


Obstacle::Obstacle() {
}

Obstacle::Obstacle(Vector2 position, GfxPtr gfx) : GameObject::GameObject(position, gfx) {
}

void Obstacle::Update(float screenWidth, float screenHeight) {

	Vector2 pos = GetPosition();
	Vector2 scrollingVector = {scrollingSpeed, 0};
	SetPosition(pos - scrollingVector);


	if (pos.x <= 0.f) {
		float randomRatio = (rand()/(float)RAND_MAX) - 0.5f;
		SetPosition({ screenWidth, screenHeight / 2 + (randomRatio * (screenHeight / 2)) });
	}
}