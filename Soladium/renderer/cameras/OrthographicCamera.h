#pragma once

#include "Camera.h"

namespace renderer 
{
	/// <summary>
	/// Камера с 2D проекцией.
	/// </summary>
	class OrthographicCamera sealed
		: public Camera
	{
		OrthographicCamera(const OrthographicCamera&) = delete;
	public:
		OrthographicCamera(const glm::vec3& position, const float& fov);
		~OrthographicCamera() = default;

		glm::mat4 getProjection() const;
	};
}