#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// TODO: cache uniforms of shader.

class Shader
{
public:
	Shader();
	Shader(const Shader&) = delete;
	~Shader();

	void loadFromFiles(const char* vertexFilename, const char* fragmentFilename);

	void bind();
	void unbind();

	void uniform(const char* name, const int& value);
	void uniform(const char* name, const glm::mat4& value);

	int getUniformLocation(const char* name);
private:
	GLuint compileShader(const GLint& type, const GLchar* source);

	GLuint m_ID;
};