#pragma once
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>

class Engine;

class MonoScript sealed
{
public:
	MonoScript();
	~MonoScript();

	void init();
private:
	//Engine& engine;

	MonoDomain* m_MonoDomain = nullptr;
	MonoAssembly* m_GameAssembly = nullptr;
	MonoImage* m_GameAssemblyImage = nullptr;
};