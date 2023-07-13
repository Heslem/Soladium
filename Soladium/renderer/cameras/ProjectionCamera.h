#pragma once

#include "Camera.h"

namespace renderer
{
	/// <summary>
	/// Камера с 3D проекцией.
	/// </summary>
	class ProjectionCamera sealed
		: public Camera
	{
		ProjectionCamera(const ProjectionCamera&) = delete;
	public:
		ProjectionCamera(const glm::vec3& position, const float& fov);
		~ProjectionCamera() = default;

		glm::mat4 getProjection() const override;
	};
}