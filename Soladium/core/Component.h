#pragma once

class GameObject;

class Component
{
public:
	Component(const char* name);
	virtual ~Component();
	Component(const Component&) = delete;

	virtual void start() = 0;
	virtual void update() = 0;
	virtual void end() {}

	void setGameObject(GameObject* object);

	const char* getName() const noexcept { return m_name; }
protected:
	const char* m_name;

	GameObject* m_gameObject;
};