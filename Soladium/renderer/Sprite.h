#pragma once

#include "textures/Texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Sprite sealed
{
public:
	Sprite(const Texture& texture);
	~Sprite();

	const Texture& getTexture() const noexcept { return m_texture; }
	const glm::mat4& getTransform() const noexcept { return m_transform; }

	void move(const float& x, const float& y);
	void scale(const float& x, const float& y);
private:
	const Texture& m_texture;
	glm::mat4 m_transform;

};