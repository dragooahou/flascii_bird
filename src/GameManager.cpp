#define _WIN32_WINNT 0x0501
#define _OE_SOCKETS

#include <random>
#include "GameManager.h"
#include <windows.h>
#include <string>
#include <iostream>

#define OBSTACLE_OFFSET_Y 30
#define INGAME_ANCHOR_X 112
#define INGAME_ANCHOR_Y 12
#define GAMEOVER_ANCHOR_X 134
#define GAMEOVER_ANCHOR_Y 37
#define RANDOM_BG_MAX 30

GameManager::GameManager() {

    srand(time(NULL));

    timer = NYTimer();
    timer.start();

    playerSprite = new AsciiSprite("assets/test.txt");
    obstacleSprite = new AsciiSprite("assets/test_tuyaux.txt");
    gameOverSprite = new AsciiSprite("assets/gameover.txt");
    moonSprite = new AsciiSprite("assets/moon.txt");

    for (int i = 0; i < 4; i++) {
        std::string path = "";
        char iTemp[3];
        sprintf(iTemp, "%d", i+1);
        std::string iString = iTemp;
        path = "assets/clouds/cloud_" + iString + ".txt";
        backgroundSprite[i] = new AsciiSprite(path);
    }
    

    for (int i = 0; i < 10; i++) {
        std::string path = "";
        char iTemp[3];
        sprintf(iTemp, "%d", i);
        std::string iString = iTemp;
        path = "assets/ascii_fonts/spliff_" + iString + ".txt";
        scoreSprite[i] = new AsciiSprite(path);
    }

    for (int i = 0; i < 3; i++) {
        std::string path = "";
        char iTemp[3];
        sprintf(iTemp, "%d", i+1);
        std::string iString = iTemp;
        path = "assets/stars/star_" + iString + ".txt";
        starSprite[i] = new AsciiSprite(path);
    }



    gameOverDisplay = GameObject({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, (std::make_shared<SimpleGraphics>(std::vector{ gameOverSprite }, IGraphics::Layer::UI)));

    inputManager = InputManager();

    scoreDisplayer = ScoreDisplayer(Vector2(INGAME_ANCHOR_X, INGAME_ANCHOR_Y), scoreSprite, IGraphics::Layer::UI);
    Init();

    isRunning = true;
    state = GameManager::GameState::RUNNING;

}

void GameManager::Update() {

    inputManager.ListenToUserInput();

    for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
        obstacle[i].Update(SCREEN_WIDTH, SCREEN_HEIGHT);
        if ((obstacle[i].GetPosition().x <= player.GetPosition().x) && !obstacle[i].isAlreadyChecked) {
            score++;
            obstacle[i].isAlreadyChecked = true;
        }
    }

    for (int i = 0; i < 4; i++) {
        backgroundObject[i].Update();
    }

    for (int i = 0; i < 8; i++) {
        starObject[i].Update();
    }
    
    moon.Update();
    player.Update(inputManager, timer);
    scoreDisplayer.Update(score);

    if (inputManager.getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
        state = GameState::ENDING;
        isRunning = false;
    }

    if (inputManager.getVirtualKeyState(VK_F3) == InputManager::Input::JUST_PRESSED) {
        renderer.SetShowColliders(!renderer.IsShowColliders());
    }

    for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
        if (player.CollideWith(obstacle[i]) && (inputManager.getVirtualKeyState(VK_LCONTROL) == InputManager::Input::RELEASED)) {
            state = GameState::GAMEOVER;
        }
    }



}

void GameManager::Render() {

    renderer.Clear();
    for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
        renderer.Render(obstacle[i]);
    }
    renderer.Render(player);
    for (int i = 0; i < 3; i++) {
        renderer.Render(scoreDisplayer.GetDisplayer(i));
    }

    for (int i = 0; i < 8; i++) {
        renderer.Render(starObject[i]);
    }

    renderer.Render(moon);

    for (int i = 0; i < 4; i++) {
        renderer.Render(backgroundObject[i]);
    }

    renderer.Present();

}

void GameManager::GameOver() {

    

    inputManager.ListenToUserInput();
    scoreDisplayer.Move(Vector2(GAMEOVER_ANCHOR_X, GAMEOVER_ANCHOR_Y));

    if (inputManager.getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
        state = GameState::ENDING;
        isRunning = false;
    }
    if (inputManager.getVirtualKeyState(VK_SPACE) == InputManager::Input::JUST_PRESSED) {
        Reset();
        state = GameState::RUNNING;
    }
    if (inputManager.getVirtualKeyState(VK_RETURN) == InputManager::Input::JUST_PRESSED) {
        state = GameState::SCOREBOARD;
    }

    renderer.Clear();
    renderer.Render(gameOverDisplay);
    for (int i = 0; i < 3; i++) {
        renderer.Render(scoreDisplayer.GetDisplayer(i));
    }
    for (int i = 0; i < 8; i++) {
        renderer.Render(starObject[i]);
    }
    renderer.Render(moon);
    for (int i = 0; i < 4; i++) {
        renderer.Render(backgroundObject[i]);
    }
    renderer.Present();

}

void GameManager::Init() {

    player = Player({ 50,33 }, std::make_shared<TextureGraphics>("assets/flappy_bird.bmp", IGraphics::Layer::OBJECTS));
    for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
        float randomRatio = (rand() / (float)RAND_MAX) - 0.5f;
        obstacle[i] = Obstacle(
            { (float)(SCREEN_WIDTH + (OBSTACLE_OFFSET * i)), SCREEN_HEIGHT / 2 + (randomRatio * (SCREEN_HEIGHT / 4) - (OBSTACLE_OFFSET_Y*(i+1))) },
            (std::make_shared<SimpleGraphics>(std::vector{ obstacleSprite }, IGraphics::Layer::OBJECTS))
        );

    }
    for (int i = 0; i < 4; i++) {
        backgroundObject[i] = BackgroundObject(1 + (float)i,
            { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * SCREEN_HEIGHT },
            (std::make_shared<SimpleGraphics>(std::vector{ backgroundSprite[i] }, IGraphics::Layer::BACKGROUND)));
    }

    moon = BackgroundObject(10000.f,
        { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, 10 },
        (std::make_shared<SimpleGraphics>(std::vector{ moonSprite }, IGraphics::Layer::BACKGROUND)));

    for (int i = 0; i < 8; i++) {
        starObject[i] = BackgroundObject(1000.f,
            { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * SCREEN_HEIGHT },
            (std::make_shared<SimpleGraphics>(std::vector{ starSprite[i % 3] }, IGraphics::Layer::BACKGROUND)));
    }
    score = 0;

}

void GameManager::Reset() {

    scoreDisplayer.Move(Vector2(INGAME_ANCHOR_X, INGAME_ANCHOR_Y));
    Init();

}
