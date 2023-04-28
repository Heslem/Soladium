#pragma once
#include <vector>
#include "VAO/Vao.h"
#include "Sprite.h"
#include "shaders/Shader.h"
#include "Camera.h"

// TODO: id to each sprite bad solution. Change.

class SpriteRenderer sealed
{
private:
	struct RendererSprite
	{
		RendererSprite(Sprite* s, const size_t& i) : sprite(s), id(i) {}

		Sprite* sprite;
		size_t id;
	};
public:
	SpriteRenderer(Shader* shader, Camera& camera);
	~SpriteRenderer();


	void draw();

	/// <summary>
	/// Returns id that need to remove
	/// </summary>
	size_t add(Sprite* sprite);
	void remove(const size_t& id);
private:

	void draw(const Sprite& sprite);
	void draw(const RendererSprite& sprite);
	// sprites to render
	std::vector<RendererSprite> m_sprites;

	Vao* m_vao;
	Shader* m_shader;
	Camera& m_camera;
};