#include "ScoreDisplayer.h"
#include "SimpleGraphics.h"
#include "Matrix.h"
#include <string>
#include <math.h>
#include <cstdlib>


ScoreDisplayer::ScoreDisplayer() {

}

ScoreDisplayer::ScoreDisplayer(Vector2 &position, AsciiSprite** fontSprite, IGraphics::Layer renderLayer) {

	SetPosition(position);
	for (int i = 0; i < 3; i++) {
		displayer[i] = GameObject({ position.x + ((float)i * 8), position.y }, (std::make_shared<SimpleGraphics>(std::vector{ &sprite[0] }, IGraphics::Layer::UI)));
	}

	for (int i = 0; i < 10; i++) {
		sprite[i] = *fontSprite[i];
	}

}

void ScoreDisplayer::Move(Vector2 &position){
	
	for (int i = 0; i < 3; i++) {
		displayer[i].SetPosition(Vector2(position.x + 9 * i, position.y));
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

	/*
	Matrix<char> matrix = Matrix<char>(4, 17);
	char scoreString[4];
	std::string stringScore;

	sprintf(scoreString, "%03d", score);
	stringScore = scoreString;
	
	std::string art[4];
	art[0] = "_________________";
	art[1] = "|-----SCORE-----|";
	art[2] = "|-----|" + stringScore + "|-----|";
	art[3] = "/_______________/";

	for (int i = 0; i < 4; i++) {
		memcpy(matrix[i], art[i].data(), 17 * sizeof(char));
	}

	sprite = AsciiSprite(matrix);

	ScoreDisplayer::SetGfx(std::make_shared<SimpleGraphics>(SimpleGraphics(std::vector{ &sprite }, IGraphics::Layer::UI)));*/

}

GameObject ScoreDisplayer::GetDisplayer(int i)
{
	return displayer[i];
}


