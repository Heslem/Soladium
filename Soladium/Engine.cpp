#include "Engine.h"
#include "utils/Keyboard.h"
#include "utils/Mouse.h"

#include <chrono>
#include <time.h>
#include "core/SpriteRendererComponent.h"

Engine::Engine()
    : m_window(new Window("Soladuim", 1200, 720)), m_camera(new ProjectionCamera(glm::vec3(0, 0, 1), glm::radians(60.0f))),
    m_framerate(60.0)
{
    Mouse::setWindow(m_window);
    Keyboard::setWindow(m_window);
    
}

Engine::~Engine()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    delete m_camera;
	delete m_window;
    delete temp_texture;
    delete temp_shader;
    delete m_spriteRenderer;
}

void Engine::run()
{
    float speed = 0.01f;

    float camX = 0.0f;
    float camY = 0.0f;
    float deltaX = Mouse::getMousePosition().x;
    float deltaY = Mouse::getMousePosition().y;

    temp_texture = new Texture("Content/Images/menu_background.png");

    temp_shader = new Shader();
    temp_shader->loadFromFiles("Content/Shaders/base_vertex.shader", "Content/Shaders/base_fragment.shader");
    temp_shader->registerUniform("u_Transform");
    temp_shader->registerUniform("u_ProjView");


    m_spriteRenderer = new SpriteRenderer(temp_shader, *m_camera);

    m_scene = new Scene();

    ScriptEngine::getInstance().init();


    test = new GameObject();
    test->addComponent(new SpriteRendererComponent(*temp_texture, *m_spriteRenderer));
    test->addComponent(ScriptEngine::getInstance().createMonoComponent("TestComponent"));

    std::cout << "add object to scene\n";
    m_scene->addGameObject(test);

    double currentTime = glfwGetTime();
    double lastTime = 0;

    double elapsed = 0;

    while (m_window->isOpen())
    {
        elapsed += currentTime - lastTime;

        m_window->pollEvents();
        
        if (elapsed > 1.0 / m_framerate) {
            update();
            elapsed = 0.0;
        }

        render();
        
        if (Keyboard::pressed(GLFW_KEY_ESCAPE)) {
            close();
        }

        lastTime = currentTime;
        currentTime = glfwGetTime();
    }
}

void Engine::update()
{
    static bool temp = false;
    if (!temp && Keyboard::pressed(GLFW_KEY_G)) {
        //test->destroy();
        temp = true;
    }

    m_scene->update();
}

void Engine::render()
{
    m_window->clear();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    m_spriteRenderer->draw();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    m_window->display();
}

void Engine::close()
{
    m_window->close();
}

Engine& Engine::getInstance()
{
    static Engine engine;
    return engine;
}

Profiler& Engine::getProfiler()
{
    return m_profiler;
}