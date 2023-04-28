#pragma once

#include "Component.h"

#include "../scripting/mono.h"

class GameObject;
class ScriptClass;

class MonoComponent sealed
	: public Component
{
public:
	MonoComponent(ScriptClass& scriptClass, MonoObject* object);
	MonoComponent(const MonoComponent&) = delete;
	~MonoComponent();

	void start() override;
	void update() override;

private:

	ScriptClass& m_scriptClass;

	MonoObject* m_monoGameObject;
	MonoObject* m_object;
};