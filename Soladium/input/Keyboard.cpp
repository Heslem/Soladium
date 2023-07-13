#include "Keyboard.h"

GLFWwindow* Keyboard::m_window;

void Keyboard::init()
{
	m_window = renderer::Window::getInstance().getGlfwWindow();
}

bool Keyboard::pressed(int keycode)
{
	return (bool)glfwGetKey(m_window, keycode);
}
