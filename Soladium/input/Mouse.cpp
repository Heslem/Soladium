#include "Mouse.h"
GLFWwindow* Mouse::m_window;
float Mouse::deltaX;
float Mouse::deltaY;
float Mouse::prevX;
float Mouse::prevY;

void Mouse::init()
{
    m_window = renderer::Window::getInstance().getGlfwWindow();
    deltaX = 0;
    deltaY = 0;
    prevX = 0;
    prevY = 0;
}

float Mouse::getX()
{
    return prevX;
}

float Mouse::getY()
{
    return prevY;
}

glm::vec2 Mouse::getMousePosition()
{
    glm::dvec2 mousePos(0, 0);
    
    glfwGetCursorPos(m_window, &mousePos.x, &mousePos.y);
    return mousePos;
}

float Mouse::getDeltaX()
{
    return deltaX;
}

float Mouse::getDeltaY()
{
    return -deltaY;
}

void Mouse::begin()
{
    auto mpos = getMousePosition();

    prevX = mpos.x;
    prevY = mpos.y;
}

void Mouse::end()
{
    auto mpos = getMousePosition();

    deltaX = mpos.x - prevX;
    deltaY = mpos.y - prevY;
}
