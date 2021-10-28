#include "TitleScene.h"
#include "InputManager.h"
#include <Windows.h>
#include "GameManager.h"

void TitleScene::Update()
{
	Scene::Update();
	InputManager::GetInstance().ListenToUserInput();

	if (InputManager::GetInstance().getVirtualKeyState(VK_SPACE) == InputManager::Input::JUST_PRESSED) {
		GameManager::GetInstance().LoadScene(1);
	}
	if (InputManager::GetInstance().getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
		GameManager::GetInstance().isRunning = false;
	}
}
