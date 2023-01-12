#pragma once
#include <iostream>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>

#include "Renderer/Window.h"
#include "Renderer/Shaders/Shader.h"
#include "Utils/Profiler.h"
#include "Renderer/Textures/Texture.h"
#include "Renderer/VAO/Vao.h"


class Engine sealed
{
public:
	~Engine();
	Engine(const Engine&) = delete;

	void run();

	static Engine& getInstance();
private:
	Engine();

	// Engine things
	Profiler m_Profiler;
	Window* m_Window;

	// C#
	MonoDomain* m_MonoDomain = nullptr;
	MonoAssembly* m_GameAssembly = nullptr;
	MonoImage* m_GameAssemblyImage = nullptr;
};