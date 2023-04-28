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
	
	template<typename T>
	T* getComponent(const char* name);

	void destroy() { m_isDestroyed = true; }
	const bool& isDestroyed() const noexcept { return m_isDestroyed; }
private:
	std::vector<Component*> m_components;

	bool m_isDestroyed;
};

template<typename T>
inline T* GameObject::getComponent(const char* name)
{
	for (size_t i = 0; i < m_components.size(); ++i)
	{
		if (m_components[i]->getName() == name)
			return static_cast<T*>(m_components[i]);
	}
	
	return nullptr;
}
