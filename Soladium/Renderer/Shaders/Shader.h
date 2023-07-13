#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <unordered_map>

namespace renderer
{
	class Shader sealed
	{
		std::unordered_map<const char*, GLint> m_cachedUniforms;

		GLuint compileShader(const GLint& shaderType, const GLchar* source);

		GLuint m_id;
	public:
		Shader();
		~Shader();

		void loadFromFiles(const char* vertexFilename, const char* fragmentFilename);
		void loadFromSources(const char* vertexSource, const char* fragmentSource);

		void bind() const;
		void unbind() const;

		void registerUniform(const char* name);

		void uniform(const char* name, const int& value);
		void uniform(const char* name, const glm::mat4& value);

		GLint getUniformLocation(const char* name) const;
	private:
		Shader(const Shader&) = delete;
		void operator=(const Shader&) = delete;
	};
}