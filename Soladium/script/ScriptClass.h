#pragma once

#include "mono.h"
#include <string>
#include <unordered_map>

namespace script
{
	class ScriptClass sealed
	{
		std::string m_name;

		MonoClass* m_monoClass;
		MonoDomain* m_domain;

		std::unordered_map<std::string, MonoMethod*> m_cachedMethods;

		friend class ScriptEngine;
		ScriptClass(const ScriptClass&) = delete;
	public:
		ScriptClass(MonoDomain* domain, MonoClass* monoClass, const std::string& name);
		~ScriptClass();

		/// <summary>
		/// Создаёт mono объект.
		/// </summary>
		MonoObject* instantiate();
		MonoMethod* getMethod(const std::string& name);
		void constructor(MonoObject* object, void** args = nullptr);
		MonoObject* invoke(MonoObject* object, const std::string& name, void** args = nullptr);

		MonoClassField* getField(const char* name) const;
		void setValue(MonoObject* object, MonoClassField* field, void* value);

		template<typename T>
		T getFieldValue(MonoObject* object, MonoClassField* field);


		const std::string& getName() const noexcept { return m_name; }
	};

	template<typename T>
	inline T ScriptClass::getFieldValue(MonoObject* object, MonoClassField* field)
	{
		T t;
		mono_field_get_value(object, field, &t);
		return t;
	}

}