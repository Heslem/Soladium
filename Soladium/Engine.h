#pragma once
#include <iostream>

#include "scripting/MonoScript.h"

#include "renderer/Window.h"
#include "renderer/shaders/Shader.h"
#include "utils/Profiler.h"
#include "renderer/Camera.h"
#include "renderer/ProjectionCamera.h"
#include "renderer/OrthographicCamera.h"
#include "renderer/SpriteRenderer.h"
#include "renderer/Sprite.h"


class Engine sealed
{
public:
	~Engine();
	Engine(const Engine&) = delete;

	void run();
	void close();

	static Engine& getInstance();

	Profiler& getProfiler();

	void setFramerateLimit(const double& framerate) { m_framerate = framerate; }
	const double& getFramerate() const noexcept { return m_framerate; }
private:
	Engine();

	void update();
	void render();

	Texture* temp_texture;
	Shader* temp_shader;
	Sprite* temp_sprite;

	SpriteRenderer* m_spriteRenderer;
	Camera* m_camera;

	double m_framerate;
	// Engine things
	Profiler m_profiler;
	Window* m_window;
	MonoScript* m_monoScript;
};