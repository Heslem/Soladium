#pragma once

#include "../Renderer/Window.h"

class Keyboard
{
public:
	static void setWindow(Window* window);

	static int pressed(const int& keycode);
private:
	static GLFWwindow* m_window;
};