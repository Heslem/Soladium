#pragma once
#include <iostream>

#include "Scripting/MonoScript.h"

#include "Renderer/Window.h"
#include "Renderer/Shaders/Shader.h"
#include "Utils/Profiler.h"
#include "Renderer/Textures/Texture.h"
#include "Renderer/VAO/Vao.h"
#include "Renderer/Camera.h"
#include "Renderer/ProjectionCamera.h"
#include "Renderer/OrthographicCamera.h"


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

	Camera* m_camera;

	// Engine things
	Profiler m_Profiler;
	Window* m_Window;
	MonoScript* m_MonoScript;
};