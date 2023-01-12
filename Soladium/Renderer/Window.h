#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Math/Color.h"
#include "../Math/Vector2.h"

class Window
{
public:
	Window(const char* title, const Vector2i& size);
	~Window();
	Window(const Window&) = delete;

	void pollEvents();
	void clear();
	void display();

	bool isOpen() const;

	void setBackgroundColor(const Color& color);
	void setTitle(const char* title);
private:

	int m_ClearMode;
	GLFWwindow* m_Window;
};