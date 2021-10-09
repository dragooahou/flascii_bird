#include "ScoreDisplayer.h"
#include "SimpleGraphics.h"
#include "Matrix.h"
#include <string>
#include <math.h>
#include <cstdlib>


ScoreDisplayer::ScoreDisplayer() {

}

ScoreDisplayer::ScoreDisplayer(const Vector2 &position, AsciiSprite** fontSprite, IGraphics::Layer renderLayer) {

	SetPosition(position);
	for (int i = 0; i < 3; i++) {
		displayer[i] = GameObject({ position.x + ((float)i * 7), position.y }, (std::make_shared<SimpleGraphics>(std::vector{ &sprite[0] }, IGraphics::Layer::UI)));
	}

	for (int i = 0; i < 10; i++) {
		sprite[i] = *fontSprite[i];
	}

}

void ScoreDisplayer::Move(const Vector2 &position){
	
	for (int i = 0; i < 3; i++) {
		displayer[i].SetPosition(Vector2(position.x + 7 * i, position.y));
	}
	
}

void ScoreDisplayer::Update(int score) {

	div_t result;
	int p = 0;
	for (int i = 2; i>=0; i--) {
		p = powf(10, i);
		result = div(score, p);
		displayer[2-i].SetGfx(std::make_shared<SimpleGraphics>(SimpleGraphics(std::vector{&(sprite[result.quot])}, IGraphics::Layer::UI)));
		score = result.rem;
	}

}

GameObject ScoreDisplayer::GetDisplayer(int i)
{
	return displayer[i];
}


