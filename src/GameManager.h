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


#define SCREEN_WIDTH    240
#define SCREEN_HEIGHT   66
#define OBSTACLE_AMOUNT 2
#define OBSTACLE_OFFSET 120
#define OBSTACLE_OFFSET_Y 30
#define INGAME_ANCHOR_X 112
#define INGAME_ANCHOR_Y 12
#define GAMEOVER_ANCHOR_X 135
#define GAMEOVER_ANCHOR_Y 36
#define RANDOM_BG_MAX 30
#define CLOUDS_AMOUNT 4
#define STARS_AMOUNT 8
#define DEBUG_MODE 1
#define NB_DIGITS 3



class GameManager {


private:

	GameManager();



	


public:

	InputManager& inputManager;
	AsciiRenderer<SCREEN_WIDTH, SCREEN_HEIGHT> renderer;
	Scene* currentScene = nullptr;

	GameManager(GameManager& other) = delete;
	void operator=(const GameManager&) = delete;

	static GameManager& GetInstance();

	int score;
	bool isRunning = false;
	static const int screenWidth = SCREEN_WIDTH;
	static const int screenHeight = SCREEN_HEIGHT;


	void Update();
	void Render();
	void LoadScene(int n);

};
