#include "GameOverScene.h"
#include "InputManager.h"
#include <Windows.h>
#include "GameManager.h"


#define LOAD_SPRITE_BATCH(array, path, count) for(int i = 0; i < count; ++i) array[i] = AsciiSprite(path + std::to_string(i) + ".txt")


/*
Creates a new GameOverScene
*/
GameOverScene::GameOverScene(int sceneID) : Scene(sceneID) {

    gameOverSprite = AsciiSprite("assets/gameover.txt");
    LOAD_SPRITE_BATCH(starSprites, "assets/stars/star_", STARS_SPRITE_AMOUNT);
    LOAD_SPRITE_BATCH(digitSprites, "assets/ascii_fonts/spliff_", DIGITS_AMOUNT);

    // Init GameOver Scene
    std::vector<GameObject*> gameOverGameObjects;
    for (int i = 0; i < 12; i++) {
        gameObjects.push_back(new BackgroundObject(1000.f,
                                                           { GameManager::SCREEN_WIDTH * (rand() / (float)RAND_MAX) + GameManager::RANDOM_BG_MAX, (rand() / (float)RAND_MAX) * GameManager::SCREEN_HEIGHT },
                                                           (std::make_shared<SimpleGraphics>(std::vector{ &starSprites[i % STARS_SPRITE_AMOUNT] }, IGraphics::Layer::BACKGROUND))));
    }

    gameObjects.push_back(new GameObject({ GameManager::SCREEN_WIDTH / 2, GameManager::SCREEN_HEIGHT / 2 }, (std::make_shared<SimpleGraphics>(std::vector{ &gameOverSprite }, IGraphics::Layer::UI))));

    std::vector<GameObject*> digits(GameManager::DISPLAYED_DIGITS);
    for (int i = 0; i < GameManager::DISPLAYED_DIGITS; i++) {
        digits[i] = new GameObject({ GameManager::SCORE_DISPLAYER_GAMEOVER_ANCHOR_X + ((float)i * 7), GameManager::SCORE_DISPLAYER_GAMEOVER_ANCHOR_Y }, (std::make_shared<SimpleGraphics>(std::vector{ &digitSprites[0] }, IGraphics::Layer::UI)));
        gameObjects.push_back(digits[i]);
    }

    gameObjects.push_back(new ScoreDisplayer(Vector2(GameManager::SCORE_DISPLAYER_GAMEOVER_ANCHOR_X, GameManager::SCORE_DISPLAYER_GAMEOVER_ANCHOR_Y), digits, digitSprites));
}


void GameOverScene::Update() {

	Scene::Update();
	InputManager::GetInstance().ListenToUserInput();

	if (InputManager::GetInstance().getVirtualKeyState(VK_SPACE) == InputManager::Input::JUST_PRESSED) {
		GameManager::GetInstance().LoadScene(1);
	}
	if (InputManager::GetInstance().getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
        GameManager::GetInstance().LoadScene(0);
	}

}