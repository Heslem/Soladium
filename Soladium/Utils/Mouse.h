#pragma once
#include <glm/glm.hpp>
#include "../Renderer/Window.h"
class Mouse {
public:
	static void setWindow(Window* window);

	static glm::vec2 getMousePosition();
private:
	static GLFWwindow* m_window;
};