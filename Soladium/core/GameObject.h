#pragma once

#include <vector>
#include "Component.h"

namespace core
{
	class GameObject sealed
	{
		std::vector<Component*> m_components;
		const char* m_name;
	public:
		GameObject(const char* name);
		~GameObject();

		void addComponent(Component* component);
		
		template<class T>
		T* getComponent(const char* name)
		{
			// TODO: можно определять компонент не по name, а по <T>
			for (size_t i = 0; i < m_components.size(); ++i)
			{
				// TODO: dynamic_cast может быть небезопасным
				if (m_components[i]->getName() == name)
					return dynamic_cast<T*>(m_components[i]);
			}
			return nullptr;
		}
		void removeComponent(const char* name);

		void begin();
		void update();
		void end();

		const char* getName() const noexcept { return m_name; }
	};
}