#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(const glm::vec3& position, const float& fov)
    : Camera(position, fov)
{
}

OrthographicCamera::~OrthographicCamera()
{
}

glm::mat4 OrthographicCamera::getProjection() const
{
    return glm::ortho(-1.2f, 1.2f, -0.72f, 0.72f, -1.0f, 100.0f);
}