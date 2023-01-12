#include "Window.h"

#include <exception>
#include "../Math/Vector2.h"
#include <iostream>

Window::Window(const char* title, const Vector2i& size)
{
    std::cout << "GLFW version: " << glfwGetVersionString() << std::endl;

    if (!glfwInit()) {
        std::cout << "Could't initialize glfw." << std::endl;
        throw std::exception();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


    m_Window = glfwCreateWindow(size.x, size.y, title, NULL, NULL);
    
    if (!m_Window) {
        std::cout << "Could't create window." << std::endl;
        throw std::exception();
    }

    glfwMakeContextCurrent(m_Window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Could't initialize glew." << std::endl;
        throw std::exception();
    }

    int width, height;
    glfwGetFramebufferSize(m_Window, &width, &height);
    glViewport(0, 0, width, height);
}

Window::~Window()
{
    glfwTerminate();
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::display()
{
    glfwSwapBuffers(m_Window);
}

bool Window::isOpen() const
{
    return !glfwWindowShouldClose(m_Window);
}

void Window::setBackgroundColor(const Color& color)
{
    glClearColor(BYTE_TO_FLOAT(color.R), BYTE_TO_FLOAT(color.G), BYTE_TO_FLOAT(color.B), 1);
}

void Window::setTitle(const char* title)
{
    glfwSetWindowTitle(m_Window, title);
}
