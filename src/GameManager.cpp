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

    isRunning = true;

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
    if(currentScene == nullptr) {
        delete currentScene;
    }

    switch (n) {

        case 1:
            currentScene = new GameScene(n);
            break;

        case 2:
            currentScene = new GameOverScene(n);
            break;

        case 0:
        default:
            currentScene = new TitleScene(n);
            break;
    }


}


GameManager& GameManager::GetInstance()
{
    static GameManager gameManager;
    return gameManager;
}