#pragma once

#include "GameObject.h"


class ScoreDisplayer : public GameObject {

public:
	ScoreDisplayer();
	ScoreDisplayer(const Vector2 &position);

	void Update(int score);

private:

	AsciiSprite sprite;
};