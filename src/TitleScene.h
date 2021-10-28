#pragma once

#include "Scene.h"


class TitleScene : public Scene {

public :
	TitleScene(std::vector<GameObject*> &gameObjects, int sceneID) : Scene(gameObjects, sceneID) {}
	void Update() override;

};