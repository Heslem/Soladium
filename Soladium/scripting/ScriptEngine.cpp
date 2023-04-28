#include "ScriptEngine.h"

#include <iostream>

// using for internal calls
#include "../utils/Keyboard.h"
#include "../core/GameObject.h"

ScriptEngine::ScriptEngine()
{
}

ScriptEngine::~ScriptEngine()
{
	mono_jit_cleanup(m_domain);

	for (auto const& pair : m_cachedClass) {
		delete pair.second;
	}
}

void ScriptEngine::registerClass(const std::string& name, const std::string& ns)
{
	m_cachedClass[name] = new ScriptClass(m_domain, mono_class_from_name(m_assemblyImage, ns.c_str(), name.c_str()), name);
}

ScriptClass* ScriptEngine::getClass(const std::string& name)
{
	return m_cachedClass[name];
}

MonoComponent* ScriptEngine::createMonoComponent(const std::string& className)
{
	auto* monoClass = m_cachedClass[className];
	return new MonoComponent(*monoClass, monoClass->instantiate());
}

void ScriptEngine::init()
{
	m_domain = mono_jit_init("Game");
	if (m_domain)
	{
		m_assembly = mono_domain_assembly_open(m_domain, "SoladuimGame.dll");
		if (m_assembly) {

			m_assemblyImage = mono_assembly_get_image(m_assembly);
			if (m_assemblyImage) {
				std::cout << "Successfully complete initialization of the script engine." << std::endl;

				addInternalCalls();

				registerClass("GameObject", "SoladuimAPI");

				registerClass("TestComponent");
			}
		}
	}
}
#include "../core/TransformComponent.h"
void temp_Move_wrap(float x, float y, GameObject* o)
{
	auto* c = o->getComponent<TransformComponent>("Transform");
	std::cout << x << std::endl;
	c->move(x, y);
}

void temp_Destroy_wrap(float x, float y, GameObject o)
{
	o.destroy();
}

void ScriptEngine::addInternalCalls()
{
	mono_add_internal_call("SoladuimAPI.SKeyboard::IsKeyPressed", &Keyboard::pressed);
	mono_add_internal_call("SoladuimAPI.GameObject::s_move", &temp_Move_wrap);
	mono_add_internal_call("SoladuimAPI.GameObject::s_destroy", &temp_Destroy_wrap);

	std::cout << "Successfully added internal calls" << std::endl;
}
