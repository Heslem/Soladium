#pragma once

namespace core
{
	class GameObject;
	class Component
	{
		Component(const Component&) = delete;
		const char* m_name;

	protected:
		//TODO: компонент следует определять через <T> 
		Component(const char* name);

		GameObject* m_gameObject;


	public:
		virtual ~Component() = default;

		virtual void begin() = 0;
		virtual void update() = 0;
		virtual void end() = 0;

		const char* getName() const noexcept { return m_name; }

		void setGameObject(GameObject* gameObject) { m_gameObject = gameObject; }
		GameObject* getGameObject() { return m_gameObject; }
	};
}