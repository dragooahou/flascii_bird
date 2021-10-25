#define _WIN32_WINNT 0x0501
#define _OE_SOCKETS

#include <random>
#include "GameManager.h"
#include <windows.h>
#include <string>
#include <iostream>



GameManager::GameManager() {

    srand(time(NULL));

    timer = NYTimer();
    timer.start();

    sprite[OBSTACLE] = new AsciiSprite("assets/obstacle.txt");
    sprite[GAMEOVER] = new AsciiSprite("assets/gameover.txt");
    sprite[TITLE] = new AsciiSprite("assets/title.txt");
    sprite[MOON] = new AsciiSprite("assets/moon.txt");

    CreateSpriteChain(CLOUD, CLOUDS_AMOUNT, "assets/clouds/cloud_");
    CreateSpriteChain(STAR, 3, "assets/stars/star_");
    CreateSpriteChain(SCORE, 10, "assets/ascii_fonts/spliff_");

    titleDisplayer = GameObject({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, (std::make_shared<SimpleGraphics>(std::vector{ sprite[TITLE] }, IGraphics::Layer::UI)));
    gameOverDisplay = GameObject({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, (std::make_shared<SimpleGraphics>(std::vector{ sprite[GAMEOVER] }, IGraphics::Layer::UI)));

    inputManager = InputManager();

    scoreDisplayer = ScoreDisplayer(Vector2(INGAME_ANCHOR_X, INGAME_ANCHOR_Y), &sprite[SCORE], IGraphics::Layer::UI);

    isRunning = true;
    state = GameManager::GameState::TITLE;
    Init();

}

void GameManager::Update() {

    inputManager.ListenToUserInput();

    switch (state) {

        case (GameState::RUNNING):

            if (inputManager.getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
                state = GameState::TITLE;
                break;
            }

            if (inputManager.getVirtualKeyState(VK_F3) == InputManager::Input::JUST_PRESSED && DEBUG_MODE) {
                renderer.SetShowColliders(!renderer.IsShowColliders());
            }

            for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
                obstacle[i].Update(SCREEN_WIDTH, SCREEN_HEIGHT);
                if ((obstacle[i].GetPosition().x <= player.GetPosition().x) && !obstacle[i].isAlreadyChecked) {
                    score++;
                    obstacle[i].isAlreadyChecked = true;
                }
                if (player.CollideWith(obstacle[i]) && (inputManager.getVirtualKeyState(VK_LCONTROL) == InputManager::Input::RELEASED) && DEBUG_MODE) {
                    scoreDisplayer.Move(Vector2(GAMEOVER_ANCHOR_X, GAMEOVER_ANCHOR_Y));
                    state = GameState::GAMEOVER;
                }
            }

            for (int i = 0; i < CLOUDS_AMOUNT; i++) {
                backgroundObject[i].Update();
            }
            for (int i = 0; i < STARS_AMOUNT; i++) {
                starObject[i].Update();
            }
            moon.Update();
            player.Update(inputManager, timer);
            scoreDisplayer.Update(score);
            break;

        case (GameState::GAMEOVER):

            if (inputManager.getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
                state = GameState::TITLE;
            }
            if (inputManager.getVirtualKeyState(VK_SPACE) == InputManager::Input::JUST_PRESSED) {
                scoreDisplayer.Move(Vector2(INGAME_ANCHOR_X, INGAME_ANCHOR_Y));
                Init();
                state = GameState::RUNNING;
            }

            break;

        case (GameState::TITLE):

            if (inputManager.getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
                state = GameState::ENDING;
                isRunning = false;
            }
            if (inputManager.getVirtualKeyState(VK_SPACE) == InputManager::Input::JUST_PRESSED) {
                scoreDisplayer.Move(Vector2(INGAME_ANCHOR_X, INGAME_ANCHOR_Y));
                Init();
                state = GameState::RUNNING;
            }

            for (int i = 0; i < STARS_AMOUNT; i++) starObject[i].Update();

            break;
    }

}

void GameManager::Render() {

    renderer.Clear();

    switch (state) {

        case (GameState::RUNNING):

            for (int i = 0; i < OBSTACLE_AMOUNT; i++) renderer.Render(obstacle[i]);
            renderer.Render(player);
            for (int i = 0; i < 3; i++) renderer.Render(scoreDisplayer.GetDisplayer(i));
            for (int i = 0; i < STARS_AMOUNT; i++) renderer.Render(starObject[i]);
            renderer.Render(moon);
            for (int i = 0; i < CLOUDS_AMOUNT; i++) renderer.Render(backgroundObject[i]);
            break;

        case (GameState::GAMEOVER):

            renderer.Render(gameOverDisplay);
            for (int i = 0; i < 3; i++) renderer.Render(scoreDisplayer.GetDisplayer(i));
            for (int i = 0; i < STARS_AMOUNT; i++) renderer.Render(starObject[i]);
            renderer.Render(moon);
            for (int i = 0; i < CLOUDS_AMOUNT; i++) renderer.Render(backgroundObject[i]);
            break;

        case (GameState::TITLE):

            renderer.Render(titleDisplayer);
            for (int i = 0; i < STARS_AMOUNT; i++) renderer.Render(starObject[i]);
            break;

    }

    renderer.Present();

}


void GameManager::Init() {

    player = Player({ 50,33 }, std::make_shared<TextureGraphics>("assets/flappy_bird.bmp", IGraphics::Layer::OBJECTS));

    for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
        float randomRatio = (rand() / (float)RAND_MAX) - 0.5f;
        obstacle[i] = Obstacle(
            { (float)(SCREEN_WIDTH + (OBSTACLE_OFFSET * i)), SCREEN_HEIGHT / 2 + (randomRatio * (SCREEN_HEIGHT / 4) - (OBSTACLE_OFFSET_Y * (i+1))) },
            (std::make_shared<SimpleGraphics>(std::vector{ sprite[OBSTACLE] }, IGraphics::Layer::OBJECTS))
        );

    }
    for (int i = 0; i < CLOUDS_AMOUNT; i++) {
        backgroundObject[i] = BackgroundObject(1 + (float)i,
            { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * SCREEN_HEIGHT },
            (std::make_shared<SimpleGraphics>(std::vector{ sprite[CLOUD + i] }, IGraphics::Layer::BACKGROUND)));
    }

    moon = BackgroundObject(10000.f,
        { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, 10 },
        (std::make_shared<SimpleGraphics>(std::vector{sprite[MOON] }, IGraphics::Layer::BACKGROUND)));

    for (int i = 0; i < 8; i++) {
        starObject[i] = BackgroundObject(1000.f,
            { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * SCREEN_HEIGHT },
            (std::make_shared<SimpleGraphics>(std::vector{ sprite[STAR + (i % 3)] }, IGraphics::Layer::BACKGROUND)));
    }

    score = 0;

}

void GameManager::CreateSpriteChain(int startingIndex, int size, std::string pathPrefix)
{
    for (int i = 0; i < size; i++) {
        std::string path = "";
        char iTemp[3];
        sprintf(iTemp, "%d", i);
        std::string iString = iTemp;
        path = pathPrefix + iString + ".txt";
        sprite[startingIndex + i] = new AsciiSprite(path);
    }
}
