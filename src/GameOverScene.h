#pragma once

#include "Scene.h"


class GameOverScene : public Scene {

public :
	GameOverScene(std::vector<GameObject*>& gameObjects, int sceneID) : Scene(gameObjects, sceneID) {}
	void Update() override;

};