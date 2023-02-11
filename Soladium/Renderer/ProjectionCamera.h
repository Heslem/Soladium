#pragma once

#include "Camera.h"

class ProjectionCamera
	: public Camera
{
public:


	ProjectionCamera(const glm::vec3& position, const float& fov);
	~ProjectionCamera();
	ProjectionCamera(const ProjectionCamera&) = delete;

	glm::mat4 getProjection() const override;
private:

};