#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace renderer {
	class Vao sealed
	{
	public:
		Vao(GLfloat* vertices, const size_t& vSize, GLuint* indices, const size_t& iSize, const GLenum& mode, const GLsizei& count);
		~Vao();

		void render();

		void bind();
		void unbind();
	private:
		GLuint m_vao, m_vbo, m_ebo;
		GLenum m_mode;
		GLsizei m_count;
	};
}