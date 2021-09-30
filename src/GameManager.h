#pragma once

#include "InputManager.h"
#include "NYTimer.h"
#include "AsciiSprite.h"
#include "utils.h"
#include "AsciiRenderer.h"
#include "TextureSprite.h"
#include "Player.h"
#include "Obstacle.h"
#include "ScoreDisplayer.h"
#include "TextureGraphics.h"

#define SCREEN_WIDTH    240
#define SCREEN_HEIGHT   66
#define OBSTACLE_AMOUNT 2
#define OBSTACLE_OFFSET 120



class GameManager {


private:
	int score;
	InputManager inputManager;
	Player player;
	NYTimer timer;
	AsciiRenderer<SCREEN_WIDTH, SCREEN_HEIGHT> renderer;
	AsciiSprite* playerSprite;
	AsciiSprite* obstacleSprite;
	Obstacle obstacle[OBSTACLE_AMOUNT];
	ScoreDisplayer scoreDisplayer;


public:


	enum class GameState {
		RUNNING,
		GAMEOVER,
		SCOREBOARD,
		ENDING
	};

	bool isRunning = false;
	GameState state;
	GameManager();
	void Update();
	void Render();
	void GameOver();
	void Reset();


};
