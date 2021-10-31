#pragma once

#include "Scene.h"
#include "Player.h"


class GameScene : public Scene {

    Player player;

    constexpr static int STAR_COUNT = 3;
    constexpr static int CLOUD_COUNT = 3;
    constexpr static int DIGIT_COUNT = 10;

    AsciiSprite cloudSprites[CLOUD_COUNT];
    AsciiSprite starSprites[STAR_COUNT];
    AsciiSprite digitSprites[DIGIT_COUNT];
    AsciiSprite obstacleSprite;
    AsciiSprite moonSprite;

public :

	GameScene(int sceneID);
	void Update() override;

};