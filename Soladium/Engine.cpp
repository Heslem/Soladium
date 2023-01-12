#include "Engine.h"

Engine::Engine()
{
    m_MonoDomain = mono_jit_init("Game");
    if (m_MonoDomain)
    {
        m_GameAssembly = mono_domain_assembly_open(m_MonoDomain, "SoladuimGame.dll");
        if (m_GameAssembly) {
            m_GameAssemblyImage = mono_assembly_get_image(m_GameAssembly);
            if (m_GameAssemblyImage) {
                
				MonoClass* ptrMainClass = mono_class_from_name(m_GameAssemblyImage, "SoladuimGame", "Game");
				if (ptrMainClass) {
					MonoMethodDesc* ptrMainMethodDesc = mono_method_desc_new(".Game:Run()", false);
					if (ptrMainMethodDesc) {
						MonoMethod* ptrMainMethod = mono_method_desc_search_in_class(ptrMainMethodDesc, ptrMainClass);
						if (ptrMainMethod) {
							MonoObject* ptrExObject = nullptr;
							 mono_runtime_invoke(ptrMainMethod, nullptr, nullptr, &ptrExObject);
						}

						mono_method_desc_free(ptrMainMethodDesc);
					}
				}
            }
        }
    }

    m_Window = new Window("Soladium", Vector2i(1200, 720));
    m_Window->setBackgroundColor(Color((BYTE_8)0, (BYTE_8)0, (BYTE_8)0));


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Engine::~Engine()
{
	delete m_Window;
    if (m_MonoDomain)
    {
        mono_jit_cleanup(m_MonoDomain);
    }
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

    while (m_Window->isOpen())
    {
        m_Window->pollEvents();
        m_Window->clear();

        texture->bind();
        shader->bind();
        shader->setUniform1i("u_Texture", 0);
        
        vao.bind();
        vao.draw();
        vao.unbind();

        shader->unbind();
        texture->unbind();


        m_Window->display();
    }
}

Engine& Engine::getInstance()
{
	static Engine engine;
	return engine;
}
