#include "Camera.h"

renderer::Camera::Camera(const glm::vec3& position, const float& fov)
	: m_fov(glm::radians(fov)), m_aspect(1200.0f / 720.0f), m_position(position), m_rotation(1.0f), m_near(0.1f), m_far(100.0f)
{
	updateVectors();
}

void renderer::Camera::updateVectors()
{
	m_front = glm::vec3(m_rotation * glm::vec4(0, 0, -1, 1));
	m_right = glm::vec3(m_rotation * glm::vec4(1, 0, 0, 1));
	m_up = glm::vec3(m_rotation * glm::vec4(0, 1, 0, 1));
}

void renderer::Camera::rotate(const float& x, const float& y, const float& z)
{
	static const glm::vec3 xAxis(1, 0, 0);
	static const glm::vec3 yAxis(0, 1, 0);
	static const glm::vec3 zAxis(0, 0, 1);

	m_rotation = glm::rotate(m_rotation, z, zAxis);
	m_rotation = glm::rotate(m_rotation, y, yAxis);
	m_rotation = glm::rotate(m_rotation, x, xAxis);

	updateVectors();
}

void renderer::Camera::setAspect(const float& aspect)
{
	m_aspect = aspect;
}

glm::mat4 renderer::Camera::getView() const
{
	return glm::lookAt(m_position, m_position + m_front, m_up);
}
