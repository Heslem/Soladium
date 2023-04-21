#include "Sprite.h"

Sprite::Sprite(const Texture& texture)
	: m_texture(texture), m_transform(1.0f)
{
}

Sprite::~Sprite()
{
}

void Sprite::move(const float& x, const float& y)
{
	m_transform = glm::translate(m_transform, glm::vec3(x, y, 0.0f));
}

void Sprite::scale(const float& x, const float& y)
{
	m_transform = glm::scale(m_transform, glm::vec3(x, y, 1.0f));
}
