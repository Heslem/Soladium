#include "GameObject.h"

core::GameObject::GameObject(const char* name)
	: m_name(name)
{
}

core::GameObject::~GameObject()
{
	for (size_t i = 0; i < m_components.size(); ++i)
	{
		delete m_components[i];
	}
	m_components.clear();
}

void core::GameObject::addComponent(Component* component)
{
	for (size_t i = 0; i < m_components.size(); ++i)
	{
		if (m_components[i]->getName() == component->getName())
			break;
	}
	m_components.push_back(component);
}

void core::GameObject::removeComponent(const char* name)
{
	for (size_t i = 0; i < m_components.size(); ++i)
	{
		if (m_components[i]->getName() == name) {
			delete m_components[i];
			m_components.erase(m_components.begin() + i);

			break;
		}
	}
}

void core::GameObject::begin()
{
	for (size_t i = 0; i < m_components.size(); ++i)
	{
		m_components[i]->begin();
	}
}

void core::GameObject::update()
{
	for (size_t i = 0; i < m_components.size(); ++i)
	{
		m_components[i]->update();
	}
}

void core::GameObject::end()
{
	for (size_t i = 0; i < m_components.size(); ++i)
	{
		m_components[i]->end();
	}
}
