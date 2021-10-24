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
#define OBSTACLE_OFFSET_Y 30
#define INGAME_ANCHOR_X 112
#define INGAME_ANCHOR_Y 12
#define GAMEOVER_ANCHOR_X 135
#define GAMEOVER_ANCHOR_Y 36
#define RANDOM_BG_MAX 30
#define CLOUDS_AMOUNT 4
#define STARS_AMOUNT 8
#define DEBUG_MODE 1



class GameManager {


private:

	enum {
		PLAYER = 0,
		OBSTACLE = 1,
		GAMEOVER = 2,
		SCORE = 3, // size 10
		CLOUD = 13, // size 4
		STAR = 17, // size 3
		MOON = 20,
		TITLE = 21,
		SIZE = 22
	};

	int score;
	InputManager inputManager;
	Player player;
	NYTimer timer;
	AsciiRenderer<SCREEN_WIDTH, SCREEN_HEIGHT> renderer;
	AsciiSprite* sprite[SIZE];
	GameObject titleDisplayer;
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
		ENDING,
		TITLE
	};

	bool isRunning = false;
	GameState state;
	void Init();
	GameManager();
	void Update();
	void Render();
	void CreateSpriteChain(int startingIndex, int size, std::string pathPrefix);

};
