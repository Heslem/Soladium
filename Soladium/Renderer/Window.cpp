#include "Window.h"

#include <exception>
#include <iostream>

#include "../utils/Log.h"

renderer::Window::Window()
    : m_glfwWindow(nullptr)
{

}

renderer::Window::~Window()
{
    glfwTerminate();
}

void renderer::Window::initialize(const char* title, const int& width, const int& height)
{
    Log::message("GLFW version:" + std::string(glfwGetVersionString()));

    if (!glfwInit()) {
        Log::error("Could't initialize glfw.");
        throw std::runtime_error("Could't initialize glfw.");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!m_glfwWindow) {
        Log::error("Could't create window.");
        std::cout << "Could't create window." << std::endl;
        throw std::runtime_error("Could't create window.");
    }

    glfwMakeContextCurrent(m_glfwWindow);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        Log::error("Could't initialize glew.");
        throw std::runtime_error("Could't initialize glew.");
    }

    glViewport(0, 0, width, height);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void renderer::Window::setVsync(const bool& value)
{
    glfwSwapInterval((int)value);
}

void renderer::Window::setCursorVisible(const bool& value)
{
    glfwSetInputMode(m_glfwWindow, GLFW_CURSOR, value ? GLFW_CURSOR_HIDDEN : GLFW_CURSOR_NORMAL);
}

void renderer::Window::setResizeable(const bool& value)
{
    glfwWindowHint(GLFW_RESIZABLE, (int)value);
}

void renderer::Window::setTitle(const char* title)
{
    glfwSetWindowTitle(m_glfwWindow, title);
}

void renderer::Window::pollEvents()
{
    glfwPollEvents();
}

void renderer::Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderer::Window::display()
{
    glfwSwapBuffers(m_glfwWindow);
}

void renderer::Window::close()
{
    glfwSetWindowShouldClose(m_glfwWindow, 1);
}

bool renderer::Window::isOpen() const
{
    return !glfwWindowShouldClose(m_glfwWindow);
}
