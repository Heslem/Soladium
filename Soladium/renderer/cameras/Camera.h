#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace renderer
{
	/// <summary>
	/// Абстрактрый класс для камеры.
	/// </summary>
	class Camera
	{
	public:
		virtual glm::mat4 getProjection() const = 0;

	private:
		Camera(const Camera&) = delete;

		glm::vec3 m_front;
		glm::vec3 m_up;
		glm::vec3 m_right;

		glm::mat4 m_rotation;
		glm::vec3 m_position;
	protected:
		Camera(const glm::vec3& position, const float& fov);
		float m_near;
		float m_far;
		
		// fov in radians
		float m_fov;
		float m_aspect;

	public:
		virtual ~Camera() = default;

		void updateVectors();

		void rotate(const float& x, const float& y, const float& z);

		void setAspect(const float& aspect);

		glm::mat4 getView() const;

		const glm::vec3& getFront() const { return m_front; }
		const glm::vec3& getUp() const { return m_up; }
		const glm::vec3& getRight() const { return m_right; }

		const glm::mat4& getRotation() const { return m_rotation; }
		const glm::vec3& getPosition() const { return m_position; }
	};
}