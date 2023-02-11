#pragma once

#include "Camera.h"

class OrthographicCamera
	: public Camera
{
public:


	OrthographicCamera(const glm::vec3& position, const float& fov);
	~OrthographicCamera();
	OrthographicCamera(const OrthographicCamera&) = delete;

	glm::mat4 getProjection() const;
private:

};