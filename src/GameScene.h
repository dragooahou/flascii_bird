#pragma once

#include "Scene.h"


class GameScene : public Scene {

public :
	GameScene(std::vector<GameObject*>& gameObjects, int sceneID) : Scene(gameObjects, sceneID) {}
	void Update() override;

};