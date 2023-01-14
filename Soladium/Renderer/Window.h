#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Math/Color.h"
#include "../Math/Vector2.h"

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