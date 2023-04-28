#include "ScriptClass.h"

#include <iostream>

ScriptClass::ScriptClass(MonoDomain* domain, MonoClass* monoClass, const std::string& name)
    : m_domain(domain), m_monoClass(monoClass), m_name(name)
{
	std::cout << "Registering class: " << m_name << std::endl;

	MonoMethod* method = nullptr;
	void* iter = NULL;

	while ((method = mono_class_get_methods(monoClass, &iter))) {
		std::string methodName(mono_method_get_name(method));

		if (methodName[0] == 's' && methodName[1] == '_')
			continue;
		else {
			m_cachedMethods[methodName] = method;
			std::cout << "Add method: " << mono_method_get_name(method) << std::endl;
		}
	}
}

ScriptClass::~ScriptClass()
{
	std::cout << "Free class: " << m_name << std::endl;
	for (auto const& pair : m_cachedMethods) {
		mono_free_method(pair.second);
	}
}

MonoObject* ScriptClass::instantiate()
{
    return mono_object_new(m_domain, m_monoClass);
}

MonoMethod* ScriptClass::getMethod(const std::string& name)
{
    return m_cachedMethods[name];
}

void ScriptClass::constructor(MonoObject* object, void** args)
{
	invoke(object, ".ctor", args);
}

MonoObject* ScriptClass::invoke(MonoObject* object, const std::string& name, void** args)
{\
    return mono_runtime_invoke(m_cachedMethods[name], object, args, NULL);
}
