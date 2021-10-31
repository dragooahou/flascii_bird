#include "Obstacle.h"
#include <random>
#include <time.h>
#include "Vector2.h"
#include "GameManager.h"


Obstacle::Obstacle(Player* player, Vector2 position, GfxPtr gfx) : GameObject(position, gfx), player(player) {

    auto rect1 = std::make_shared<Colliders::Rectangle>();
    rect1->size = Vector2(16, 59);
    collider.colliders.push_back(rect1);

    auto rect2 = std::make_shared<Colliders::Rectangle>();
    rect2->size = Vector2(16, 59);
    rect2->position.y = 82;
    collider.colliders.push_back(rect2);

}

void Obstacle::Update() {

	Vector2 pos = GetPosition();
	Vector2 scrollingVector = {SCROLLING_SPEED, FALLING_SPEED};
	SetPosition(pos - scrollingVector);

    if (CollideWith(*player)) {
        GameManager::GetInstance().LoadScene(2);
    }

    if (pos.x <= 50.f && !isBehindPlayer) {
        GameManager::GetInstance().score++;
        isBehindPlayer = true;
    }

	if (pos.x <= 0.f) {
		float randomRatio = (rand()/(float)RAND_MAX) - 0.5f;
		SetPosition({GameManager::SCREEN_WIDTH, GameManager::SCREEN_HEIGHT / 2 + (randomRatio * (GameManager::SCREEN_HEIGHT / 2) - FALLING_OFFSET) });
        isBehindPlayer = false;
	}

    collider.position = GetPosition() - GetGfx()->GetCurrentFrame()->GetCenterOffset();

}

const Colliders::ICollider *Obstacle::GetCollider() const {
    return &collider;
}
