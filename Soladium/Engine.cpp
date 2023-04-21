#include "Engine.h"
#include "utils/Keyboard.h"
#include "utils/Mouse.h"

#include <chrono>
#include <time.h>

Engine::Engine()
    : m_window(new Window("Soladuim", 1200, 720)), m_camera(new ProjectionCamera(glm::vec3(0, 0, 1), glm::radians(60.0f))),
    m_monoScript(new MonoScript()), m_framerate(60.0)
{
    Mouse::setWindow(m_window);
    Keyboard::setWindow(m_window);

    


    temp_texture = new Texture("Content/Images/menu_background.png");
    
    temp_shader = new Shader();
    temp_shader->loadFromFiles("Content/Shaders/base_vertex.shader", "Content/Shaders/base_fragment.shader");
    temp_shader->registerUniform("u_Transform");
    temp_shader->registerUniform("u_ProjView");

    temp_sprite = new Sprite(*temp_texture);

    m_spriteRenderer = new SpriteRenderer(temp_shader, *m_camera);
}

Engine::~Engine()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    delete m_camera;
    delete m_monoScript;
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


    m_monoScript->init();
    //auto* comp = m_MonoScript->createMonoComponent("TestComponent");

    //comp->start();

    // TODO: add delta time

    while (m_window->isOpen())
    {
        m_window->pollEvents();
        update();
        render();
        
        if (Keyboard::pressed(GLFW_KEY_ESCAPE)) {
            close();
        }
    }
}

void Engine::update()
{

}

void Engine::render()
{
    m_window->clear();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    temp_sprite->move(0.001f, 0);
    m_spriteRenderer->draw(*temp_sprite);


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