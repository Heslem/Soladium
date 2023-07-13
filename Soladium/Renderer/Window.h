#pragma once
#include "../utils/Singleton.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace renderer
{
	class Window sealed
	{
		SINGLETON(Window)

			GLFWwindow* m_glfwWindow;
	public:
		void initialize(const char* title, const int& width, const int& height);
		void setVsync(const bool& value);
		void setCursorVisible(const bool& value);
		void setResizeable(const bool& value);
		void setTitle(const char* title);

		void pollEvents();
		void clear();
		void display();
		void close();

		bool isOpen() const;

		GLFWwindow* getGlfwWindow() { return m_glfwWindow; }
	};
}