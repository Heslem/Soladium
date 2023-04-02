#include "Keyboard.h"

GLFWwindow* Keyboard::m_window;

void Keyboard::setWindow(Window* window)
{
	m_window = window->getGLFWWindow();
}

bool Keyboard::pressed(int keycode)
{
	return (bool)glfwGetKey(m_window, keycode);
}
