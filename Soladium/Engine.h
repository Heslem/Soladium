#pragma once
#include "utils/Singleton.h"

#include <iostream>
#include "renderer/shaders/Shader.h"
#include "renderer/vao/Vao.h"
#include "renderer/textures/Texture.h"
#include "renderer/cameras/ProjectionCamera.h"
#include "renderer/SpriteRenderer.h"
#include "core/State.h"

#include "input/Keyboard.h"
#include "input/Mouse.h"

class Engine sealed
{
	SINGLETON(Engine)

		renderer::Shader* m_shader;
	renderer::Texture* m_texture;
	renderer::Camera* m_camera;
	renderer::SpriteRenderer* m_spriteRenderer;
	core::State* m_state;

	static float m_deltaTime;
	// TODO: add ups
public:

	void run();
	void close();

	static const float& getDeltaTime() { return m_deltaTime; }
	renderer::SpriteRenderer& getSpriteRenderer() const { return *m_spriteRenderer; }

};