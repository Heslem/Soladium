#include "ScriptClass.h"
#include "../utils/Log.h"

script::ScriptClass::ScriptClass(MonoDomain* domain, MonoClass* monoClass, const std::string& name)
	: m_domain(domain), m_monoClass(monoClass), m_name(name)
{
	Log::message(std::string("Registering class: ").append(m_name));

	MonoMethod* method = nullptr;
	void* iter = NULL;
	
	while ((method = mono_class_get_methods(monoClass, &iter))) {
		std::string methodName(mono_method_get_name(method));

		if (methodName[0] == 's' && methodName[1] == '_') // We do not add extern methods.
			continue;
		else {
			m_cachedMethods[methodName] = method;
			Log::message(std::string("Add method: ").append(methodName));
		}
	}
}

script::ScriptClass::~ScriptClass()
{
	Log::message(std::string("Free class: ").append(m_name));
	for (auto& pair : m_cachedMethods)
	{
		mono_free_method(pair.second);
	}
}

MonoObject* script::ScriptClass::instantiate()
{
	return mono_object_new(m_domain, m_monoClass);
}

MonoMethod* script::ScriptClass::getMethod(const std::string& name)
{
	return m_cachedMethods[name];
}

void script::ScriptClass::constructor(MonoObject* object, void** args)
{
	invoke(object, ".ctor", args);
}

MonoObject* script::ScriptClass::invoke(MonoObject* object, const std::string& name, void** args)
{
	return mono_runtime_invoke(m_cachedMethods[name], object, args, NULL);
}

MonoClassField* script::ScriptClass::getField(const char* name) const
{
	return mono_class_get_field_from_name(m_monoClass, name);
}

void script::ScriptClass::setValue(MonoObject* object, MonoClassField* field, void* value)
{
	mono_field_set_value(object, field, value);
}
