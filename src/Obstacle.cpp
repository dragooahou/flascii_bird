#include "Obstacle.h"
#include <random>
#include <time.h>
#include "Vector2.h"


Obstacle::Obstacle() {

}

Obstacle::Obstacle(Vector2 position, Graphics gfx) : GameObject::GameObject(position, gfx) {

}

void Obstacle::Update(float screenWidth, float screenHeight) {

	Vector2 pos = GetPosition();
	Vector2 scrollingVector = {scrollingSpeed, 0};
	SetPosition(pos - scrollingVector);


	if (pos.x <= 0.f) {
		srand((time(0)));
		SetPosition({ screenWidth, (rand()%1000 / 1000.f) * screenHeight});
	}
}