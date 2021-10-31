#include "TitleScene.h"
#include "InputManager.h"
#include <Windows.h>
#include "GameManager.h"


#define LOAD_SPRITE_BATCH(array, path, count) for(int i = 0; i < count; ++i) array[i] = AsciiSprite(path + std::to_string(i) + ".txt")


TitleScene::TitleScene(int sceneID) : Scene(sceneID) {

    // Load sprites
    titleSprite    = AsciiSprite("assets/title.txt");
    LOAD_SPRITE_BATCH(starSprites, "assets/stars/star_", STAR_COUNT);


    // Init Title Scene
    for (int i = 0; i < STAR_COUNT; i++) {
        gameObjects.push_back(new BackgroundObject(1000.f,
                                    { GameManager::SCREEN_WIDTH * (rand() / (float)RAND_MAX) + GameManager::RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * GameManager::SCREEN_HEIGHT },
                                    (std::make_shared<SimpleGraphics>(std::vector{ &starSprites[i] }, IGraphics::Layer::BACKGROUND))));
    }

    gameObjects.push_back(new GameObject({ GameManager::SCREEN_WIDTH / 2, GameManager::SCREEN_HEIGHT / 2 }, (std::make_shared<SimpleGraphics>(std::vector{ &titleSprite }, IGraphics::Layer::UI))));

}


void TitleScene::Update() {

	Scene::Update();
	InputManager::GetInstance().ListenToUserInput();

	if (InputManager::GetInstance().getVirtualKeyState(VK_SPACE) == InputManager::Input::JUST_PRESSED) {
		GameManager::GetInstance().LoadScene(1);
	}
	if (InputManager::GetInstance().getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
		GameManager::GetInstance().isRunning = false;
	}

}