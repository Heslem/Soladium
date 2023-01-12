#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	Shader();
	Shader(const Shader&) = delete;
	~Shader();

	void loadFromFiles(const char* vertexFilename, const char* fragmentFilename);

	void bind();
	void unbind();

	void setUniform1i(const char* name, const int& value);

	int getUniformLocation(const char* name);
private:
	GLuint compileShader(const GLint& type, const GLchar* source);

	GLuint m_ID;
};