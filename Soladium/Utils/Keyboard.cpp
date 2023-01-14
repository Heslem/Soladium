#include "Keyboard.h"

GLFWwindow* Keyboard::m_window;

void Keyboard::setWindow(Window* window)
{
	m_window = window->getGLFWWindow();
}

int Keyboard::pressed(const int& keycode)
{
	return glfwGetKey(m_window, keycode);
}
