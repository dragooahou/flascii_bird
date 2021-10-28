#pragma once

#include "Scene.h"


class GameOverScene : public Scene {

    constexpr static int STAR_COUNT = 3;
    constexpr static int DIGIT_COUNT = 10;

    AsciiSprite gameOverSprite;
    AsciiSprite starSprites[STAR_COUNT];
    AsciiSprite digitSprites[DIGIT_COUNT];


public :
	GameOverScene(int sceneID);
	void Update() override;

};