#include "Camera.h"

Camera::Camera(const glm::vec3& position, const float& fov)
    : m_fov(fov), m_aspect(1200.0f / 720.0f), position(position), rotation(1.0f), m_near(0.1f), m_far(100.0f)
{
    updateVectors();
}

Camera::~Camera()
{
}

void Camera::updateVectors()
{
    front = glm::vec3(rotation * glm::vec4(0, 0, -1, 1));
    right = glm::vec3(rotation * glm::vec4(1, 0, 0, 1));
    up = glm::vec3(rotation * glm::vec4(0, 1, 0, 1));
}

void Camera::rotate(const float& x, const float& y, const float& z)
{
    rotation = glm::rotate(rotation, z, glm::vec3(0, 0, 1));
    rotation = glm::rotate(rotation, y, glm::vec3(0, 1, 0));
    rotation = glm::rotate(rotation, x, glm::vec3(1, 0, 0));

    updateVectors();
}

void Camera::setAspect(const float& aspect)
{
    m_aspect = aspect;
}

glm::mat4 Camera::getProjection() const
{
    return glm::perspective(m_fov, m_aspect, m_near, m_far);
}

glm::mat4 Camera::getView() const
{
    return glm::lookAt(position, position + front, up);
}
