#pragma once

#include "../Component.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace core
{
	namespace component
	{
		class TransformComponent sealed
			: public Component
		{
			glm::mat4 m_transform;
		public:
			TransformComponent();
			~TransformComponent();

			void begin() override;
			void update() override;
			void end() override;

			void move(const float& x, const float& y, const float& z = 0.0f);
			void scale(const float& x, const float& y, const float& z = 1.0f);

			const glm::mat4& getTransform() const noexcept { return m_transform; }
		};
	}
}