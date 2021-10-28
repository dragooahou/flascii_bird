#include "Scene.h"


Scene::~Scene()
{
	for (GameObject* go : gameObjects) {
		delete go;
	}
}

void Scene::Update() {
	for (GameObject* go : gameObjects) {
		go->Update();
	}
}
