#pragma once
#include "mono.h"

#include <string>
#include <unordered_map>

#include "../core/components/MonoComponent.h"

#include "ScriptClass.h"

#include "../utils/Singleton.h"

namespace script
{
	class ScriptEngine sealed
	{
		SINGLETON(ScriptEngine)
			friend class Engine;

		MonoDomain* m_domain = nullptr;
		MonoAssembly* m_assembly = nullptr;
		MonoImage* m_assemblyImage = nullptr;

		std::unordered_map<std::string, ScriptClass*> m_cachedClass;

		void init();
		void addInternalCalls();
	public:

		void registerClass(const std::string& name, const std::string& ns = "SoladuimGame");
		ScriptClass* getClass(const std::string& name);

		core::component::MonoComponent* createMonoComponent(const std::string& className);
	};
}