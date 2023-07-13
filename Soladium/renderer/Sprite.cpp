#include "Sprite.h"

renderer::Sprite::Sprite(const glm::mat4& transform, Texture* texture)
	: transform(transform), texture(texture)
{
}

renderer::Sprite::~Sprite()
{
}
