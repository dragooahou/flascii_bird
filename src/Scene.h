#pragma once
#include "GameObject.h"

class Scene {

public:

	Scene() = default;

	Scene(std::vector<GameObject*> &gameObjects, int sceneID) : gameObjects(gameObjects), sceneID(sceneID) {}
	std::vector<GameObject*> gameObjects;
	virtual void Update();
	virtual ~Scene();
	const int sceneID = -1;

private :

	
	



};