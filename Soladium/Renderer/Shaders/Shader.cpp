#include "Shader.h"

#include "../../Utils/FileUtils.h"

Shader::Shader()
	: m_ID(0)
{
}

Shader::~Shader()
{
	glDeleteProgram(m_ID);
}

void Shader::loadFromFiles(const char* vertexFilename, const char* fragmentFilename)
{
	const char* vertexSource = readFile(vertexFilename).c_str();
	const char* fragmentSource = readFile(fragmentFilename).c_str();

	GLuint vertexID = compileShader(GL_VERTEX_SHADER, vertexSource);
	GLuint fragmentID = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

	if (vertexID == -1 || fragmentID == -1) {
		return;
	}

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexID);
	glAttachShader(m_ID, fragmentID);
	glLinkProgram(m_ID);
	
	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_ID, 512, nullptr, infoLog);
		std::cerr << "PROGRAM LINKING FAILED" << std::endl;
		std::cerr << infoLog << std::endl;

		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);
	}

	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}

void Shader::bind()
{
	glUseProgram(m_ID);
}

void Shader::unbind()
{
	glUseProgram(0);
}

void Shader::uniform(const char* name, const int& value)
{
	glUniform1i(getUniformLocation(name), value);
}

void Shader::uniform(const char* name, const glm::mat4& value)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
}

int Shader::getUniformLocation(const char* name)
{
	return glGetUniformLocation(m_ID, name);
}

GLuint Shader::compileShader(const GLint& type, const GLchar* source)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR " << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " SHADER COMPILATION_FAILED" << std::endl << infoLog << std::endl;
		return -1;
	}

	return shader;
}
