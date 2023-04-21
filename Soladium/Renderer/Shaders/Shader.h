#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <unordered_map>

class Shader
{
public:
	Shader();
	Shader(const Shader&) = delete;
	~Shader();

	void loadFromFiles(const char* vertexFilename, const char* fragmentFilename);
	void loadFromSource(const char* vertexSource, const char* fragmentSource);

	void bind();
	void unbind();

	void registerUniform(const char* name);

	void uniform(const char* name, const int& value);
	void uniform(const char* name, const glm::mat4& value);

	GLint getUniformLocation(const char* name);
private:
	std::unordered_map<const char*, GLint> m_cachedUniforms;

	GLuint compileShader(const GLint& type, const GLchar* source);

	GLuint m_ID;
};