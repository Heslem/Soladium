#pragma once

#include "../renderer/Window.h"

class Keyboard
{
public:
	static void setWindow(Window* window);

	static bool pressed(int keycode);
private:
	static GLFWwindow* m_window;
};