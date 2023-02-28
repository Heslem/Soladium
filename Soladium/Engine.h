#pragma once
#include <iostream>

#include "Scripting/MonoScript.h"

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
	void close();

	static Engine& getInstance();

	Profiler& getProfiler();
private:
	Engine();

	// Engine things
	Profiler m_Profiler;
	Window* m_Window;
	MonoScript* m_MonoScript;
};