#include "GameScene.h"
#include "InputManager.h"
#include <Windows.h>
#include "GameManager.h"

void GameScene::Update()
{
    Scene::Update();
    InputManager::GetInstance().ListenToUserInput();

    if (GameManager::GetInstance().inputManager.getVirtualKeyState(VK_F3) == InputManager::Input::JUST_PRESSED && DEBUG_MODE) {
        GameManager::GetInstance().renderer.SetShowColliders(!GameManager::GetInstance().renderer.IsShowColliders());
    }
}
