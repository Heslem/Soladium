#include "Component.h"

#include "GameObject.h"

Component::Component(const char* name)
	: m_gameObject(nullptr), m_name(name)
{
}

Component::~Component()
{
}

void Component::setGameObject(GameObject* object)
{
	m_gameObject = object;
}
