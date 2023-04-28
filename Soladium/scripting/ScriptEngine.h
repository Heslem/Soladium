#pragma once

#include "mono.h"

#include <string>
#include <unordered_map>

#include "../core/MonoComponent.h"

#include "ScriptClass.h"


class ScriptEngine sealed
{
private:
	ScriptEngine();
public:
	~ScriptEngine();
	ScriptEngine(const ScriptEngine&) = delete;
	
	static ScriptEngine& getInstance()
	{
		static ScriptEngine instance;
		return instance;
	}

	void registerClass(const std::string& name, const std::string& ns = "SoladuimGame");
	ScriptClass* getClass(const std::string& name);

	MonoComponent* createMonoComponent(const std::string& className);

private:

	void init();
	void addInternalCalls();

	MonoDomain* m_domain = nullptr;
	MonoAssembly* m_assembly = nullptr;
	MonoImage* m_assemblyImage = nullptr;

	std::unordered_map<std::string, ScriptClass*> m_cachedClass;

	friend class Engine;
};