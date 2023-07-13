#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace renderer
{
	class Texture sealed
	{
		Texture(const Texture&) = delete;
		void operator=(const Texture&) = delete;

		GLuint m_id;

		int m_width;
		int m_height;
		unsigned char* m_pixels;
		int m_bpp;
	public:
		Texture(const char* path);
		~Texture();

		void bind() const;
		void unbind() const;

		const int& getWidth() const noexcept { return m_width; }
		const int& getHeight() const noexcept { return m_height; }
	};
}