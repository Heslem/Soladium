#include "Engine.h"
#include "Utils/Keyboard.h"
#include "Utils/Mouse.h"



Engine::Engine()
    : m_Window(new Window("Soladuim", 1200, 720)), m_camera(new ProjectionCamera(glm::vec3(0, 0, 1), glm::radians(60.0f))),
    m_MonoScript(new MonoScript())
{
    Mouse::setWindow(m_Window);
    Keyboard::setWindow(m_Window);
}

Engine::~Engine()
{
    delete m_camera;
    delete m_MonoScript;
	delete m_Window;
}

void Engine::run()
{
    Shader* shader = new Shader();
    shader->loadFromFiles("Content/Shaders/base.vert", "Content/Shaders/base.frag");

    Texture* texture = new Texture("Content/Images/menu_background.png");

    GLfloat vertices[] = {
        // Позиции          // Цвета             // Текстурные координаты
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Верхний правый
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Нижний правый
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Нижний левый
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // Верхний левый
    };
    GLuint indices[] = {
        0, 1, 3,
        1, 2, 3
    };
    Vao vao(vertices, sizeof(vertices), indices, sizeof(indices), GL_TRIANGLES, 6);
   
    float speed = 0.01f;

    float camX = 0.0f;
    float camY = 0.0f;
    float deltaX = Mouse::getMousePosition().x;
    float deltaY = Mouse::getMousePosition().y;


    m_MonoScript->init();
    auto* comp = m_MonoScript->createMonoComponent("TestComponent");

    comp->start();

    // TODO: add delta time

    bool* b = new bool(true);
    while (m_Window->isOpen())
    {
        m_Window->pollEvents();
        m_Window->clear();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow(b);

        //comp->update();

        

        deltaX -= Mouse::getMousePosition().x;
        deltaY -= Mouse::getMousePosition().y;

        if (Keyboard::pressed(GLFW_KEY_ESCAPE)) {
            close();
        }
        
        if (Keyboard::pressed(GLFW_KEY_W)) {
            m_camera->position += m_camera->front * speed;
        }
        if (Keyboard::pressed(GLFW_KEY_S)) {
            m_camera->position -= m_camera->front * speed;
        }
        if (Keyboard::pressed(GLFW_KEY_D)) {
            m_camera->position += m_camera->right * speed;
        }
        if (Keyboard::pressed(GLFW_KEY_A)) {
            m_camera->position -= m_camera->right * speed;
        }

        camY += deltaY / 720 * 2;
        camX += deltaX / 720 * 2;

        if (camY < -glm::radians(89.0f)) {
            camY = -glm::radians(89.0f);
        }
        if (camY > glm::radians(89.0f)) {
            camY = glm::radians(89.0f);
        }

        m_camera->rotation = glm::mat4(1.0f);
        m_camera->rotate(camY, camX, 0);



        texture->bind();
        shader->bind();
        shader->uniform("u_Texture", 0);
        glm::mat4 trans(1.0f);
        trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
        //trans = glm::rotate(trans, (GLfloat)glfwGetTime() * 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));

        shader->uniform("u_Transform", trans);
        shader->uniform("u_ProjView", m_camera->getProjection() * m_camera->getView());
        vao.bind();
        vao.draw();
        vao.unbind();

        shader->unbind();
        texture->unbind();


        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        deltaX = Mouse::getMousePosition().x;
        deltaY = Mouse::getMousePosition().y;

        m_Window->display();
    }
}

void Engine::close()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    m_Window->close();
   
}

Engine& Engine::getInstance()
{
	static Engine engine;
	return engine;
}

Profiler& Engine::getProfiler()
{
    return m_Profiler;
}
