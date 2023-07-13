#include "ScriptEngine.h"

#include "../utils/Log.h"

// using for internal calls
#include "../input/Keyboard.h"
#include "../input/Mouse.h"
#include "../core/GameObject.h"
#include "../Engine.h"

script::ScriptEngine::ScriptEngine()
{

}

script::ScriptEngine::~ScriptEngine()
{
	for (auto const& pair : m_cachedClass) {
		delete pair.second;
	}
	mono_jit_cleanup(m_domain);
}

void script::ScriptEngine::init()
{
	m_domain = mono_jit_init("Game");
	if (m_domain)
	{
		m_assembly = mono_domain_assembly_open(m_domain, "SoladuimGame.dll");
		if (m_assembly) {

			m_assemblyImage = mono_assembly_get_image(m_assembly);
			if (m_assemblyImage) {
				Log::message("Successfully complete initialization of the script engine.");

				addInternalCalls();

				registerClass("GameObject", "SoladuimAPI");
			}
		}
	}
}

void script::ScriptEngine::registerClass(const std::string& name, const std::string& ns)
{
	m_cachedClass[name] = new ScriptClass(m_domain, mono_class_from_name(m_assemblyImage, ns.c_str(), name.c_str()), name);
}

script::ScriptClass* script::ScriptEngine::getClass(const std::string& name)
{
	return m_cachedClass[name];
}

core::component::MonoComponent* script::ScriptEngine::createMonoComponent(const std::string& className)
{
	auto* monoClass = m_cachedClass[className];
	return new core::component::MonoComponent(*monoClass, monoClass->instantiate());
}

#include "../core/components/TransformComponent.h"
void temp_Move_wrap(float& x, float& y, void*& o)
{
	core::GameObject* obj = static_cast<core::GameObject*>(o);
	auto* c = obj->getComponent<core::component::TransformComponent>("transform");
	//std::cout << x << std::endl;
	c->move(x, y);
}

void temp_Destroy_wrap(float x, float y, void* o)
{
	//o->destroy();
}

void script::ScriptEngine::addInternalCalls()
{
	mono_add_internal_call("SoladuimAPI.SEngine::GetDeltaTime", &::Engine::getDeltaTime);

	mono_add_internal_call("SoladuimAPI.SKeyboard::IsKeyPressed", &Keyboard::pressed);

	mono_add_internal_call("SoladuimAPI.SMouse::GetX", &Mouse::getX);
	mono_add_internal_call("SoladuimAPI.SMouse::GetY", &Mouse::getY);
	mono_add_internal_call("SoladuimAPI.SMouse::GetDeltaX", &Mouse::getDeltaX);
	mono_add_internal_call("SoladuimAPI.SMouse::GetDeltaY", &Mouse::getDeltaY);

	mono_add_internal_call("SoladuimAPI.GameObject::s_move", &temp_Move_wrap);
	mono_add_internal_call("SoladuimAPI.GameObject::s_destroy", &temp_Destroy_wrap);

	Log::message("Successfully added internal calls");
}
