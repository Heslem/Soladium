#include "MonoComponent.h"

#include <iostream>
#include "../scripting/ScriptClass.h"
#include "../scripting/ScriptEngine.h"

MonoComponent::MonoComponent(ScriptClass& scriptClass, MonoObject* object)
	: Component(scriptClass.getName().c_str()), m_scriptClass(scriptClass), m_object(object)
	
{
}

MonoComponent::~MonoComponent()
{
}

void MonoComponent::start()
{
	auto& engineScript = ScriptEngine::getInstance();
	auto* gameObjectClass = engineScript.getClass("GameObject");
	
	std::cout << "Create game object" << std::endl;

	auto* monoGameObject = gameObjectClass->instantiate();
	
	if (!monoGameObject)
		std::cout << "Mono object is null." << std::endl;

	void* argsCtor[1];
	argsCtor[0] = &m_gameObject;

	gameObjectClass->constructor(monoGameObject, argsCtor);

	void* args[1];
	args[0] = &monoGameObject;

	m_scriptClass.invoke(m_object, "Start", args);
}

void MonoComponent::update()
{
	m_scriptClass.invoke(m_object, "Update");
}
