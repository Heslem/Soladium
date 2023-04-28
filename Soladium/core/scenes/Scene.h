#pragma once

#include <vector>
#include "../../renderer/SpriteRenderer.h"
#include "../GameObject.h"

class Scene
{
public:
	Scene();
	~Scene();

	void update();

	void addGameObject(GameObject* object);
private:

	std::vector<GameObject*> m_gameObjects;
};