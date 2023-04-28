#include "Sprite.h"

Sprite::Sprite(const Texture& texture, const glm::mat4& transform)
	: m_texture(texture), m_transform(transform)
{
}

Sprite::~Sprite()
{
}