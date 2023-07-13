#include "OrthographicCamera.h"

renderer::OrthographicCamera::OrthographicCamera(const glm::vec3& position, const float& fov)
	: Camera(position, fov)
{
}

glm::mat4 renderer::OrthographicCamera::getProjection() const
{
	// TODO: значения должны расчитываться динамически.
	return glm::ortho(-1.2f, 1.2f, -0.72f, 0.72f, -1.0f, 100.0f);
}
