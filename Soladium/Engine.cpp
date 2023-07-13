#include "Engine.h"

#include "utils/Log.h"
#include "renderer/Window.h"
#include "core/GameObject.h"
#include "core/components/TransformComponent.h"
#include "core/components/SpriteComponent.h"
#include "utils/VaoGenerator.h"
#include "script/ScriptEngine.h"
#include "core/components/MonoComponent.h"
#include "utils/Profiler.h"

float Engine::m_deltaTime;

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::run()
{
    Log::init();
    renderer::Window& window = renderer::Window::getInstance();
    window.initialize("Soladium Engine 1.0.", 1200, 720);
    window.setVsync(true);

    Mouse::init();
    Keyboard::init();

    m_shader = new renderer::Shader();
    m_shader->loadFromFiles("Content/Shaders/base_vertex.shader", "Content/Shaders/base_fragment.shader");
    m_shader->registerUniform("u_Transform");
    m_shader->registerUniform("u_ProjView");

    m_texture = new renderer::Texture("Content/Images/menu_background.png");

    m_camera = new renderer::ProjectionCamera(glm::vec3(0, 0, 1), 60.0f);
    m_spriteRenderer = new renderer::SpriteRenderer();
    m_spriteRenderer->setShader(m_shader);
    m_spriteRenderer->setCamera(m_camera);

    m_state = new core::State("game");

    auto& scriptEngine = script::ScriptEngine::getInstance();
    scriptEngine.init();
    scriptEngine.registerClass("ExampleComponent");

    //for (size_t i = 0; i < 1; i++)
    //{
        core::GameObject* object = new core::GameObject("go");
        auto* transformComp = new core::component::TransformComponent();
        object->addComponent(transformComp);
        auto* sprite = new renderer::Sprite(transformComp->getTransform(), m_texture);
        object->addComponent(new core::component::SpriteComponent(sprite));

        core::component::MonoComponent* monoComponent = scriptEngine.createMonoComponent("ExampleComponent");
        monoComponent->setGameObject(object);

        object->addComponent(monoComponent);

        m_state->instantiate(object);
   // }

    m_state->run();
    m_state->begin();
    double previous = glfwGetTime();
    double lag = 0.0;

    Profiler& profiler = Profiler::getInstance();

    while (window.isOpen())
    {
        double current = glfwGetTime();
        m_deltaTime = current - previous;
        previous = current;
        lag += m_deltaTime;


        while (lag >= 1.0 / 60.0)
        {
            window.pollEvents();

            m_state->update();
            lag -= 1.0 / 60.0;
        }

       
        window.clear();

        //profiler.begin("renderer");
        m_spriteRenderer->render();
        //std::cout << profiler.end().getInMilliseconds() << " ms\n";

        window.display();
    }
    m_state->end();
}

void Engine::close()
{
    renderer::Window::getInstance().close();

    delete m_shader;
    delete m_texture;
    delete m_camera;
}