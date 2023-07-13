#include "ProjectionCamera.h"

renderer::ProjectionCamera::ProjectionCamera(const glm::vec3& position, const float& fov)
    : Camera(position, fov)
{
}

glm::mat4 renderer::ProjectionCamera::getProjection() const
{
    return glm::perspective(m_fov, m_aspect, m_near, m_far);
}
