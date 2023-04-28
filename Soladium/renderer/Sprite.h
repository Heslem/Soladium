#pragma once

#include "textures/Texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Sprite sealed
{
public:
	Sprite(const Texture& texture, const glm::mat4& transform);
	~Sprite();

	const Texture& getTexture() const noexcept { return m_texture; }
	const glm::mat4& getTransform() const noexcept { return m_transform; }

	
private:
	const Texture& m_texture;
	const glm::mat4& m_transform;

};