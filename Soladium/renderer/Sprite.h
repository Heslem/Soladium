#pragma once

#include "vao/Vao.h"
#include "textures/Texture.h"

#include <glm/glm.hpp>

#include "../utils/VaoGenerator.h"

namespace renderer
{
	struct Sprite sealed
	{
		Sprite(const glm::mat4& transform, Texture* texture);
		~Sprite();

		const glm::mat4& transform;
		Texture* texture;
	};
}