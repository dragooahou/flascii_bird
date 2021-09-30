#include "ScoreDisplayer.h"
#include "SimpleGraphics.h"
#include "Matrix.h"
#include <string>


ScoreDisplayer::ScoreDisplayer() {

}

ScoreDisplayer::ScoreDisplayer(const Vector2 &position) {

	SetPosition(position);

}

void ScoreDisplayer::Update(int score) {

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

	ScoreDisplayer::SetGfx(std::make_shared<SimpleGraphics>(SimpleGraphics(std::vector{ &sprite }, IGraphics::Layer::UI)));

}