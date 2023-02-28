#include "Window.h"

#include <exception>
#include <iostream>

Window::Window(const char* title, const int& width, const int& height)
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


    m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
    
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

    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN); 

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::display()
{
    glfwSwapBuffers(m_Window);
}

void Window::close()
{
    glfwSetWindowShouldClose(m_Window, 1);
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
