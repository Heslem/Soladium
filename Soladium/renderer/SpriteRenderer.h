#pragma once

#include "VAO/Vao.h"
#include "Sprite.h"
#include "shaders/Shader.h"
#include "Camera.h"

class SpriteRenderer sealed
{
public:
	SpriteRenderer(Shader* shader, Camera& camera);
	~SpriteRenderer();

	void draw(const Sprite& sprite);
private:
	Vao* m_vao;
	Shader* m_shader;
	Camera& m_camera;
};