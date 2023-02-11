#include "ProjectionCamera.h"

ProjectionCamera::ProjectionCamera(const glm::vec3& position, const float& fov)
    : Camera(position, fov)
{
}

ProjectionCamera::~ProjectionCamera()
{
}

glm::mat4 ProjectionCamera::getProjection() const
{
    return glm::perspective(m_fov, m_aspect, m_near, m_far);
}
