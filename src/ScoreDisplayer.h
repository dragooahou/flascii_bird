#pragma once

#include "GameObject.h"


class ScoreDisplayer : public GameObject {

public:
	ScoreDisplayer() = default;
	ScoreDisplayer(const Vector2 &position, const std::vector<GameObject*> &displayer);
	void Move(const Vector2& position);

	void Update() override;
	GameObject* GetDisplayer(int i);

private:

	IGraphics::Layer layer = IGraphics::Layer::UI;
	std::vector<GameObject*> displayer;
	AsciiSprite sprite[10];
};