#pragma once

#include "Component.h"
#include <vector>

class GameObject sealed
{
public:
	GameObject();
	~GameObject();
	
	void start();
	void update();

	void addComponent(Component* component);
private:
	std::vector<Component*> m_components;
};
