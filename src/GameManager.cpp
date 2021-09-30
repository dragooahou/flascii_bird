#define _WIN32_WINNT 0x0501

#include <random>
#include "GameManager.h"
#include <windows.h>
#include <iostream>

GameManager::GameManager() {

    srand(time(NULL));

    timer = NYTimer();
    timer.start();

    playerSprite = new AsciiSprite("assets/test.txt");
    obstacleSprite = new AsciiSprite("assets/test_tuyaux.txt");

    inputManager = InputManager();

    player = Player({ 20,20 }, std::make_shared<TextureGraphics>("assets/flappy_bird.bmp", SimpleGraphics::Layer::OBJECTS));

    for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
        float randomRatio = (rand() / (float)RAND_MAX) - 0.5f;
        obstacle[i] = Obstacle(
            { (float)(SCREEN_WIDTH + (OBSTACLE_OFFSET * i)), SCREEN_HEIGHT / 2 + (randomRatio * (SCREEN_HEIGHT / 4)) },
            (std::make_shared<SimpleGraphics>(std::vector{ obstacleSprite }, SimpleGraphics::Layer::OBJECTS))
        );

    }

    score = 0;
    scoreDisplayer = ScoreDisplayer({ SCREEN_WIDTH / 2, 5 });

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

    player.Update(inputManager, timer);
    scoreDisplayer.Update(score);

    if (inputManager.getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
        state = GameState::ENDING;
        isRunning = false;
    }

    for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
        if (player.CollideWith(obstacle[i])) {
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
    renderer.Render(scoreDisplayer);
    renderer.Present();

}

void GameManager::GameOver() {

    inputManager.ListenToUserInput();

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
}

void GameManager::Reset() {

    player = Player({ 20,20 }, std::make_shared<TextureGraphics>("assets/flappy_bird.bmp", SimpleGraphics::Layer::OBJECTS));

    for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
        float randomRatio = (rand() / (float)RAND_MAX) - 0.5f;
        obstacle[i] = Obstacle(
            { (float)(SCREEN_WIDTH + (OBSTACLE_OFFSET * i)), SCREEN_HEIGHT / 2 + (randomRatio * (SCREEN_HEIGHT / 4)) },
            (std::make_shared<SimpleGraphics>(std::vector{ obstacleSprite }, SimpleGraphics::Layer::OBJECTS))
        );

    }

    score = 0;

}
