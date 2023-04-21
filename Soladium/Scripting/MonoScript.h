#pragma once
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>

#include <string>
#include <unordered_map>

#include "../core/MonoComponent.h"

class MonoScript sealed
{
public:
	MonoScript();
	~MonoScript();

	void registerClass(const char* className, const char* ns = "SoladuimGame");

	/// <summary>
	/// .class:method()
	/// </summary>
	void registerMethodDesc(const char* name);

	/// <summary>
	/// Don't forget register methodDecs before it.
	/// </summary>
	/// <param name="methodDesc">.class:method()</param>
	void registerMethod(const char* methodDesc, const char* className);

	/// <summary>
	/// Don't forget register method and methodDecs before it.
	/// </summary>
	/// <param name="methodDesc">.class:method()</param>
	/// <returns></returns>
	MonoMethod* getMethod(const char* methodDesc);

	MonoObject* createMonoObject(const char* className);

	// TODO: I think need cache component and change component class.

	MonoComponent* createMonoComponent(const std::string& className, const bool& registered = false);

	void init();
private:

	std::unordered_map<const char*, MonoClass*> m_cachedClasses;
	std::unordered_map<const char*, MonoMethodDesc*> m_cachedMethodDesc;
	std::unordered_map<const char*, MonoMethod*> m_cachedMethods;

	MonoDomain* m_MonoDomain = nullptr;
	MonoAssembly* m_GameAssembly = nullptr;
	MonoImage* m_GameAssemblyImage = nullptr;
};