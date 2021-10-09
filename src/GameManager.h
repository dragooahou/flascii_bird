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
#include "BackgroundObject.h"


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
	AsciiSprite* gameOverSprite;
	AsciiSprite* scoreSprite[10];
	AsciiSprite* backgroundSprite[4];
	AsciiSprite* starSprite[3];
	AsciiSprite* moonSprite;
	GameObject gameOverDisplay;
	Obstacle obstacle[OBSTACLE_AMOUNT];
	BackgroundObject backgroundObject[4];
	BackgroundObject moon;
	BackgroundObject starObject[8];
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
	void Init();
	GameManager();
	void Update();
	void Render();
	void GameOver();
	void Reset();

};
