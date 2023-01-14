#include "Mouse.h"
GLFWwindow* Mouse::m_window;

void Mouse::setWindow(Window* window)
{
    m_window = window->getGLFWWindow();
}

glm::vec2 Mouse::getMousePosition()
{
    glm::dvec2 mousePos(0, 0);
    
    glfwGetCursorPos(m_window, &mousePos.x, &mousePos.y);
    return mousePos;
}
