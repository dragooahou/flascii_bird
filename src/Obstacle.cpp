#include "Obstacle.h"
#include <random>
#include <time.h>
#include "Vector2.h"


Obstacle::Obstacle() {

}

Obstacle::Obstacle(Vector2 position, GfxPtr gfx) : GameObject::GameObject(position, gfx) {

    auto rect1 = std::make_shared<Colliders::Rectangle>();
    rect1->size = Vector2(16, 59);
    collider.colliders.push_back(rect1);

    auto rect2 = std::make_shared<Colliders::Rectangle>();
    rect2->size = Vector2(16, 59);
    rect2->position.y = 82;
    collider.colliders.push_back(rect2);
}

void Obstacle::Update(float screenWidth, float screenHeight) {

	Vector2 pos = GetPosition();
	Vector2 scrollingVector = {scrollingSpeed, 0};
	SetPosition(pos - scrollingVector);


	if (pos.x <= 0.f) {
		float randomRatio = (rand()/(float)RAND_MAX) - 0.5f;
		SetPosition({ screenWidth, screenHeight / 2 + (randomRatio * (screenHeight / 2)) });
		isAlreadyChecked = false;
	}

    collider.position = GetPosition() - GetGfx()->GetCurrentFrame()->GetCenterOffset();
}

const Colliders::ICollider *Obstacle::GetCollider() const {
    return &collider;
}
