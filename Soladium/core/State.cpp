#include "State.h"

core::State::State(const char* name)
	: m_name(name)
{
}

core::State::~State()
{
	for (size_t i = 0; i < m_objects.size(); ++i)
	{
		delete m_objects[i];
	}
}

void core::State::run()
{
    m_isRunning = true;
}

void core::State::begin()
{
	for (size_t i = 0; i < m_objects.size(); ++i)
	{
		m_objects[i]->begin();
	}
}

void core::State::update()
{
	for (size_t i = 0; i < m_objects.size(); ++i)
	{
		m_objects[i]->update();
	}
}

void core::State::end()
{
	for (size_t i = 0; i < m_objects.size(); ++i)
	{
		m_objects[i]->end();
	}
}

void core::State::instantiate(GameObject* object)
{
    m_objects.push_back(object);
    if (m_isRunning)
        object->begin();
}