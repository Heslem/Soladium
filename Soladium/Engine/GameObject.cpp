#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
	for (size_t i = 0; i < m_components.size(); i++)
	{
		delete m_components[i];
	}
}

void GameObject::start()
{
	for (size_t i = 0; i < m_components.size(); ++i)
	{
		m_components[i]->start();
	}
}

void GameObject::update()
{
	for (size_t i = 0; i < m_components.size(); ++i)
	{
		m_components[i]->update();
	}
}

void GameObject::addComponent(Component* component)
{
	m_components.push_back(component);
}
