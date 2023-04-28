#pragma once

#include "mono.h"
#include <string>
#include <unordered_map>


class ScriptClass
{
private:
	ScriptClass(MonoDomain* domain, MonoClass* monoClass, const std::string& name);
public:
	ScriptClass(const ScriptClass&) = delete;
	~ScriptClass();

	MonoObject* instantiate();
	MonoMethod* getMethod(const std::string& name);
	void constructor(MonoObject* object, void** args = nullptr);
	MonoObject* invoke(MonoObject* object, const std::string& name, void** args = nullptr);

	const std::string& getName() const noexcept { return m_name; }
private:
	std::string m_name;

	MonoClass* m_monoClass;
	MonoDomain* m_domain;

	std::unordered_map<std::string, MonoMethod*> m_cachedMethods;

	friend class ScriptEngine;
};