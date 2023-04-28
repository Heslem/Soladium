#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::update()
{
	for (size_t i = 0; i < m_gameObjects.size(); ++i)
	{
		if (m_gameObjects[i]->isDestroyed()) {
			delete m_gameObjects[i];
			m_gameObjects.erase(m_gameObjects.begin() + i);
			i--;
		}
		else {
			m_gameObjects[i]->update();
		}
	}
}

void Scene::addGameObject(GameObject* object)
{
	m_gameObjects.push_back(object);
	object->start();
}
