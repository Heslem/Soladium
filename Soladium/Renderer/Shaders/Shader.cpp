#include "Shader.h"
#include "../../utils/Log.h"
#include "../../utils/FileSystem.h"

GLuint renderer::Shader::compileShader(const GLint& shaderType, const GLchar* source)
{
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);

		Log::error(std::string((shaderType == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT")) + " SHADER COMPILATION_FAILED");
		Log::error(infoLog);
		return -1;
	}

	return shader;
}

renderer::Shader::Shader()
    : m_id(0)
{
}

renderer::Shader::~Shader()
{
	glDeleteProgram(m_id);
}

void renderer::Shader::loadFromFiles(const char* vertexFilename, const char* fragmentFilename)
{
	FileSystem& fs = FileSystem::getInstance();

	loadFromSources(fs.read(vertexFilename).c_str(), fs.read(fragmentFilename).c_str());
}

void renderer::Shader::loadFromSources(const char* vertexSource, const char* fragmentSource)
{
	GLuint vertexID = compileShader(GL_VERTEX_SHADER, vertexSource);
	GLuint fragmentID = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

	if (vertexID == -1 || fragmentID == -1)
		return;

	m_id = glCreateProgram();
	glAttachShader(m_id, vertexID);
	glAttachShader(m_id, fragmentID);
	glLinkProgram(m_id);

	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(m_id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_id, 512, nullptr, infoLog);
		Log::error("PROGRAM LINKING FAILED");
		Log::error(infoLog);

		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);
	}

	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}

void renderer::Shader::bind() const
{
	glUseProgram(m_id);
}

void renderer::Shader::unbind() const
{
	glUseProgram(0);
}

void renderer::Shader::registerUniform(const char* name)
{
	GLint uniformId = getUniformLocation(name);
	if (uniformId != -1)
		m_cachedUniforms[name] = uniformId;
	else
		Log::error(std::string("Can't find shader uniform: ").append(name));
		
}

void renderer::Shader::uniform(const char* name, const int& value)
{
	glUniform1i(m_cachedUniforms[name], value);
}

void renderer::Shader::uniform(const char* name, const glm::mat4& value)
{
	glUniformMatrix4fv(m_cachedUniforms[name], 1, GL_FALSE, glm::value_ptr(value));
}

GLint renderer::Shader::getUniformLocation(const char* name) const
{
	return glGetUniformLocation(m_id, name);
}
