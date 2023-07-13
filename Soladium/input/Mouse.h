#pragma once
#include <glm/glm.hpp>
#include "../renderer/Window.h"
class Mouse {
public:

	static float getX();
	static float getY();

	static float getDeltaX();
	static float getDeltaY();
private:
	static void init();
	static GLFWwindow* m_window;
	
	static float deltaX;
	static float deltaY;
	static float prevX;
	static float prevY;

	static glm::vec2 getMousePosition();
	static void begin();
	static void end();

	friend class Engine;
};