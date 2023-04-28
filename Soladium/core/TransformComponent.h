#pragma once

#include "Component.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class TransformComponent sealed
	: public Component
{
public:
	TransformComponent();
	~TransformComponent();

	void start() override;
	void update() override;
	void end() override;

	void move(const float& x, const float& y);
	void scale(const float& x, const float& y);

	const glm::mat4& getTransform() const noexcept { return m_transform; }
private:

	glm::mat4 m_transform;
};