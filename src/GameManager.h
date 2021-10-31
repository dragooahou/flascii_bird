#pragma once

#include "InputManager.h"
#include "Timer.h"
#include "AsciiSprite.h"
#include "utils.h"
#include "AsciiRenderer.h"
#include "TextureSprite.h"
#include "Player.h"
#include "Obstacle.h"
#include "ScoreDisplayer.h"
#include "TextureGraphics.h"
#include "BackgroundObject.h"
#include "Scene.h"


class GameManager {

private:

	GameManager();

public:
	static constexpr int SCREEN_WIDTH = 240;
	static constexpr int SCREEN_HEIGHT = 66;
	static constexpr int OBSTACLE_AMOUNT = 2;
	static constexpr int OBSTACLE_OFFSET = 120;
	static constexpr int OBSTACLE_OFFSET_Y = 30;
	static constexpr int SCORE_DISPLAYER_INGAME_ANCHOR_X = 112;
	static constexpr int SCORE_DISPLAYER_INGAME_ANCHOR_Y = 12;
	static constexpr int SCORE_DISPLAYER_GAMEOVER_ANCHOR_X = 135;
	static constexpr int SCORE_DISPLAYER_GAMEOVER_ANCHOR_Y = 36;
	static constexpr int RANDOM_BG_MAX = 30;
	static constexpr int CLOUDS_AMOUNT = 4;
	static constexpr int INGAME_STARS_AMOUNT = 8;
	static constexpr int MENUS_STARS_AMOUNT = 12;
	static constexpr int DISPLAYED_DIGITS = 3;

	static constexpr bool DEBUG_MODE = false;



	InputManager& inputManager;
	AsciiRenderer<SCREEN_WIDTH, SCREEN_HEIGHT> renderer;
	Scene* currentScene = nullptr;

	GameManager(GameManager& other) = delete;
	void operator=(const GameManager&) = delete;

	static GameManager& GetInstance();

	int score;
	bool isRunning = false;

	void Update();
	void Render();
	void LoadScene(int n);

};
