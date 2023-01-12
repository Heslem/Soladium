#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Vao sealed
{
public:
	Vao(GLfloat* vertices, const unsigned long long& vSize, GLuint* indices, const unsigned long long& iSize, const GLenum& mode, const GLsizei& count);
	~Vao();

	void draw();

	void bind();
	void unbind();
private:
	GLuint VBO, VAO, EBO;
	GLenum m_Mode;
	GLsizei m_Count;
};