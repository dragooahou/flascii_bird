#include "GameScene.h"
#include "InputManager.h"
#include <Windows.h>
#include "GameManager.h"

#define LOAD_SPRITE_BATCH(array, path, count) for(int i = 0; i < count; ++i) array[i] = AsciiSprite(path + std::to_string(i) + ".txt")

/*
Creates a GameScene
*/
GameScene::GameScene(int sceneID) : Scene(sceneID) {

    // Load sprites
    obstacleSprite = AsciiSprite("assets/obstacle.txt");
    moonSprite = AsciiSprite("assets/moon.txt");
    LOAD_SPRITE_BATCH(starSprites, "assets/stars/star_", STAR_COUNT);
    LOAD_SPRITE_BATCH(cloudSprites, "assets/clouds/cloud_", CLOUD_COUNT);
    LOAD_SPRITE_BATCH(digitSprites, "assets/ascii_fonts/spliff_", DIGIT_COUNT);



    // Init Game Scene
    player = Player({ 50,33 }, std::make_shared<TextureGraphics>("assets/flappy_bird.bmp", IGraphics::Layer::OBJECTS));
    gameObjects.push_back(&player);

    for (int i = 0; i < GameManager::OBSTACLE_AMOUNT; i++) {
        float randomRatio = (rand() / (float)RAND_MAX) - 0.5f;
        gameObjects.push_back(new Obstacle(
                &player,
                { (float)(GameManager::SCREEN_WIDTH + (GameManager::OBSTACLE_OFFSET * i)), GameManager::SCREEN_HEIGHT / 2 + (randomRatio * (GameManager::SCREEN_HEIGHT / 4) - (GameManager::OBSTACLE_OFFSET_Y * (i + 1))) },
                (std::make_shared<SimpleGraphics>(std::vector{ &obstacleSprite }, IGraphics::Layer::OBJECTS)))
        );
    }

    for (int i = 0; i < GameManager::INGAME_STARS_AMOUNT; i++) {
        gameObjects.push_back(new BackgroundObject(1000.f,
                                                       { GameManager::SCREEN_WIDTH * (rand() / (float)RAND_MAX) + GameManager::RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * GameManager::SCREEN_HEIGHT },
                                                       (std::make_shared<SimpleGraphics>(std::vector{ &starSprites[i % STAR_COUNT] }, IGraphics::Layer::BACKGROUND))));
    }

    for (int i = 0; i < GameManager::CLOUDS_AMOUNT; i++) {
        gameObjects.push_back(new BackgroundObject(1 + (float)i,
                                                       { GameManager::SCREEN_WIDTH * (rand() / (float)RAND_MAX) + GameManager::RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * GameManager::SCREEN_HEIGHT },
                                                       (std::make_shared<SimpleGraphics>(std::vector{ &cloudSprites[i % CLOUD_COUNT] }, IGraphics::Layer::BACKGROUND))));
    }

    gameObjects.push_back(new BackgroundObject(10000.f,
                                                   { GameManager::SCREEN_WIDTH * (rand() / (float)RAND_MAX) + GameManager::RANDOM_BG_MAX, 10 },
                                                   (std::make_shared<SimpleGraphics>(std::vector{ &moonSprite }, IGraphics::Layer::BACKGROUND))));

    std::vector<GameObject*> digits(GameManager::DISPLAYED_DIGITS);
    for (int i = 0; i < GameManager::DISPLAYED_DIGITS; i++) {
        digits[i] = new GameObject({ GameManager::SCORE_DISPLAYER_INGAME_ANCHOR_X + ((float)i * 7), GameManager::SCORE_DISPLAYER_INGAME_ANCHOR_Y }, (std::make_shared<SimpleGraphics>(std::vector{ &digitSprites[0] }, IGraphics::Layer::UI)));
        gameObjects.push_back(digits[i]);
    }

    gameObjects.push_back(new ScoreDisplayer(Vector2(GameManager::SCORE_DISPLAYER_INGAME_ANCHOR_X, GameManager::SCORE_DISPLAYER_INGAME_ANCHOR_Y), digits, digitSprites));


    // Set score to 0 (should be stored here actually D:)
    GameManager::GetInstance().score = 0;
}


void GameScene::Update() {

    Scene::Update();
    InputManager::GetInstance().ListenToUserInput();

    if (GameManager::GetInstance().inputManager.getVirtualKeyState(VK_F3) == InputManager::Input::JUST_PRESSED && GameManager::DEBUG_MODE) {
        GameManager::GetInstance().renderer.SetShowColliders(!GameManager::GetInstance().renderer.IsShowColliders());
    }

}