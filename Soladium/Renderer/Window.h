#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

#include "../math/Color.h"
#include "../math/Vector2.h"

class Window
{
public:
	Window(const char* title, const int& width, const int& height);
	~Window();
	Window(const Window&) = delete;

	void pollEvents();
	void clear();
	void display();
	void close();

	bool isOpen() const;

	void setBackgroundColor(const Color& color);
	void setTitle(const char* title);

	GLFWwindow* getGLFWWindow() { return m_Window; }
private:

	

	GLFWwindow* m_Window;
};