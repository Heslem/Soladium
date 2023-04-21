#pragma once
#include <glm/glm.hpp>
#include "../renderer/Window.h"
class Mouse {
public:
	static void setWindow(Window* window);

	static glm::vec2 getMousePosition();
private:
	static GLFWwindow* m_window;
};