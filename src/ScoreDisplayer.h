#pragma once

#include "GameObject.h"


class ScoreDisplayer : public GameObject {

public:
	ScoreDisplayer();
	ScoreDisplayer(const Vector2 &position, AsciiSprite** fontSprite, IGraphics::Layer renderLayer);
	void Move(const Vector2& position);

	void Update(int score);
	GameObject GetDisplayer(int i);

private:

	IGraphics::Layer layer = IGraphics::Layer::UI;
	GameObject displayer[3];
	AsciiSprite sprite[10];
};