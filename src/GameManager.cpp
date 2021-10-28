#define _WIN32_WINNT 0x0501
#define _OE_SOCKETS

#include <random>
#include "GameManager.h"
#include <windows.h>
#include <string>
#include <iostream>
#include "Scene.h"
#include "TitleScene.h"
#include "GameOverScene.h"
#include "GameScene.h"



GameManager::GameManager() : inputManager(InputManager::GetInstance()) {

    srand(time(NULL));
    Timer::GetInstance().Start();

    sprite[OBSTACLE] = new AsciiSprite("assets/obstacle.txt");
    sprite[GAMEOVER] = new AsciiSprite("assets/gameover.txt");
    sprite[TITLE] = new AsciiSprite("assets/title.txt");
    sprite[MOON] = new AsciiSprite("assets/moon.txt");

    CreateSpriteChain(CLOUD, CLOUDS_AMOUNT, "assets/clouds/cloud_");
    CreateSpriteChain(STAR, 3, "assets/stars/star_");
    CreateSpriteChain(SCORE, 10, "assets/ascii_fonts/spliff_");

    isRunning = true;

    // Init Title Scene
    std::vector<GameObject*> titleGameObjects;
    for (int i = 0; i < 12; i++) {
        titleGameObjects.push_back(new BackgroundObject(1000.f,
            { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * SCREEN_HEIGHT },
            (std::make_shared<SimpleGraphics>(std::vector{ sprite[STAR + (i % 3)] }, IGraphics::Layer::BACKGROUND))));
    }
    titleGameObjects.push_back(new GameObject({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, (std::make_shared<SimpleGraphics>(std::vector{ sprite[TITLE] }, IGraphics::Layer::UI))));
    scenes.push_back(new TitleScene(titleGameObjects, 0));

    // Init Game Scene
    std::vector<GameObject*> mainGameObjects;
    Player* player = new Player({ 50,33 }, std::make_shared<TextureGraphics>("assets/flappy_bird.bmp", IGraphics::Layer::OBJECTS));
    mainGameObjects.push_back(player);
    for (int i = 0; i < OBSTACLE_AMOUNT; i++) {
        float randomRatio = (rand() / (float)RAND_MAX) - 0.5f;
        mainGameObjects.push_back(new Obstacle(
            player,
            { (float)(SCREEN_WIDTH + (OBSTACLE_OFFSET * i)), SCREEN_HEIGHT / 2 + (randomRatio * (SCREEN_HEIGHT / 4) - (OBSTACLE_OFFSET_Y * (i + 1))) },
            (std::make_shared<SimpleGraphics>(std::vector{ sprite[OBSTACLE] }, IGraphics::Layer::OBJECTS)))
        );
    }
    for (int i = 0; i < STARS_AMOUNT; i++) {
        mainGameObjects.push_back(new BackgroundObject(1000.f,
            { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * SCREEN_HEIGHT },
            (std::make_shared<SimpleGraphics>(std::vector{ sprite[STAR + (i % 3)] }, IGraphics::Layer::BACKGROUND))));
    }
    for (int i = 0; i < CLOUDS_AMOUNT; i++) {
        mainGameObjects.push_back(new BackgroundObject(1 + (float)i,
            { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * SCREEN_HEIGHT },
            (std::make_shared<SimpleGraphics>(std::vector{ sprite[CLOUD + i] }, IGraphics::Layer::BACKGROUND))));
    }
    mainGameObjects.push_back(new BackgroundObject(10000.f,
        { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, 10 },
        (std::make_shared<SimpleGraphics>(std::vector{ sprite[MOON] }, IGraphics::Layer::BACKGROUND))));
    std::vector<GameObject*> digit(NB_DIGITS);
    for (int i = 0; i < NB_DIGITS; i++) {
        digit[i] = new GameObject({ INGAME_ANCHOR_X + ((float)i * 7), INGAME_ANCHOR_Y }, (std::make_shared<SimpleGraphics>(std::vector{ sprite[SCORE] }, IGraphics::Layer::UI)));
        mainGameObjects.push_back(digit[i]);
    }
    mainGameObjects.push_back(new ScoreDisplayer(Vector2(INGAME_ANCHOR_X, INGAME_ANCHOR_Y), sprite[SCORE], (std::make_shared<SimpleGraphics>(std::vector{ sprite[SCORE] }, IGraphics::Layer::UI)), digit));

    scenes.push_back(new GameScene(mainGameObjects, 1));

    // Init GameOver Scene
    std::vector<GameObject*> gameOverGameObjects;
    for (int i = 0; i < 12; i++) {
        gameOverGameObjects.push_back(new BackgroundObject(1000.f,
            { SCREEN_WIDTH * (rand() / (float)RAND_MAX) + RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * SCREEN_HEIGHT },
            (std::make_shared<SimpleGraphics>(std::vector{ sprite[STAR + (i % 3)] }, IGraphics::Layer::BACKGROUND))));
    }
    gameOverGameObjects.push_back(new GameObject({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, (std::make_shared<SimpleGraphics>(std::vector{ sprite[GAMEOVER] }, IGraphics::Layer::UI))));
    std::vector<GameObject*> digits(NB_DIGITS);
    for (int i = 0; i < NB_DIGITS; i++) {
        digits[i] = new GameObject({ GAMEOVER_ANCHOR_X + ((float)i * 7), GAMEOVER_ANCHOR_Y }, (std::make_shared<SimpleGraphics>(std::vector{ sprite[SCORE] }, IGraphics::Layer::UI)));
        mainGameObjects.push_back(digits[i]);
    }
    mainGameObjects.push_back(new ScoreDisplayer(Vector2(GAMEOVER_ANCHOR_X, GAMEOVER_ANCHOR_Y), sprite[SCORE], (std::make_shared<SimpleGraphics>(std::vector{ sprite[SCORE] }, IGraphics::Layer::UI)), digits));

    scenes.push_back(new GameOverScene(gameOverGameObjects, 2));

    LoadScene(0);
}

void GameManager::Update() {

    currentScene->Update();

}

void GameManager::Render() {

    renderer.Clear();
    for (GameObject* go : currentScene->gameObjects) {
        renderer.Render(*go);
    }

    renderer.Present();

}

void GameManager::LoadScene(int n)
{

    currentScene = scenes[n];
}


GameManager& GameManager::GetInstance()
{
    static GameManager gameManager;
    return gameManager;
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
