#include "MonoComponent.h"
#include "../../utils/Log.h"
#include "../../script/ScriptEngine.h"

core::component::MonoComponent::MonoComponent(script::ScriptClass& scriptClass, MonoObject* object)
	: Component(scriptClass.getName().c_str()), m_scriptClass(scriptClass), m_object(object)
{
}

core::component::MonoComponent::~MonoComponent()
{
	
}

void core::component::MonoComponent::begin()
{
	auto& engineScript = script::ScriptEngine::getInstance();
	auto* gameObjectClass = engineScript.getClass("GameObject");

	m_monoGameObject = gameObjectClass->instantiate();

	if (!m_monoGameObject)
		Log::error("Mono object is null.");

	void* argsCtor[1];
	argsCtor[0] = &m_gameObject;

	gameObjectClass->constructor(m_monoGameObject, argsCtor);

	void* args[1];
	// TODO: попробовать без &
	args[0] = &m_monoGameObject;

	m_scriptClass.invoke(m_object, "Begin", args);
}

void core::component::MonoComponent::update()
{
	m_scriptClass.invoke(m_object, "Update");
}

void core::component::MonoComponent::end()
{
	m_scriptClass.invoke(m_object, "End");
}
