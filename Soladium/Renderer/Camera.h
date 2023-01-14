#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera sealed
{
public:
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;

	glm::mat4 rotation;
	glm::vec3 position;

	Camera(const glm::vec3& position, const float& fov);
	~Camera();
	Camera(const Camera&) = delete;

	void updateVectors();

	void rotate(const float& x, const float& y, const float& z);

	void setAspect(const float& aspect);

	glm::mat4 getProjection() const;
	glm::mat4 getView() const;


private:
	float m_near;
	float m_far;
	float m_fov;
	float m_aspect;
};