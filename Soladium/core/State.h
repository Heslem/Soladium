#pragma once

#include <vector>
#include "GameObject.h"

namespace core
{
	class State
	{
		std::vector<GameObject*> m_objects;
		bool m_isRunning;
		const char* m_name;
	public:
		State(const char* name);
		~State();

		void run();

		void begin();
		void update();
		void end();

		void instantiate(GameObject* object);
		GameObject* getObjectByName(const char* name)
		{
			for (size_t i = 0; i < m_objects.size(); ++i)
			{
				if (m_objects[i]->getName() == name)
					return m_objects[i];
			}
			return nullptr;
		}

		const char* getName() const noexcept { return m_name; }
	};

	
}