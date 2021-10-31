#include "ScoreDisplayer.h"
#include "SimpleGraphics.h"
#include "Matrix.h"
#include <string>
#include <math.h>
#include <cstdlib>
#include "GameManager.h"



ScoreDisplayer::ScoreDisplayer(const Vector2 &position, const std::vector<GameObject*> &displayer, AsciiSprite* sprite) : GameObject(), displayer(displayer), sprite(sprite) {
    SetPosition(position);
}

void ScoreDisplayer::Move(const Vector2 &position) {
	for (int i = 0; i < 3; i++) {
		displayer[i]->SetPosition(Vector2(position.x + 7 * i, position.y));
	}
}

void ScoreDisplayer::Update() {

	div_t result;
	int p = 0;

	for (int i = 2; i>=0; i--) {
		p = powf(10, i);
		result = div(GameManager::GetInstance().score, p);
		displayer.at(2-i)->SetGfx(std::make_shared<SimpleGraphics>(std::vector{sprite + result.quot}, IGraphics::Layer::UI));
	}

}

GameObject* ScoreDisplayer::GetDisplayer(int i) {
	return displayer[i];
}



