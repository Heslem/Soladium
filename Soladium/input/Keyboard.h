#pragma once

#include "../renderer/Window.h"

class Keyboard
{
public:

	static bool pressed(int keycode);
private:
	static void init();
	static GLFWwindow* m_window;

	friend class Engine;
};