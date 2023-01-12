#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>



class Texture sealed
{
public:
	Texture(const char* path);
	~Texture();

	void bind();
	void unbind();

private:
	GLuint m_Id;

	int m_Width;
	int m_Height;
	unsigned char* m_Pixels;
	int m_Bpp;
};