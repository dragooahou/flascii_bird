#pragma once

#include "Scene.h"


class GameOverScene : public Scene {

    constexpr static int STARS_SPRITE_AMOUNT = 3;
    constexpr static int DIGITS_AMOUNT = 10;

    AsciiSprite gameOverSprite;
    AsciiSprite starSprites[STARS_SPRITE_AMOUNT];
    AsciiSprite digitSprites[DIGITS_AMOUNT];


public :

	GameOverScene(int sceneID);
	void Update() override;

};