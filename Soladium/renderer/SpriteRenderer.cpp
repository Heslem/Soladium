#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(Shader* shader, Camera& camera)
    : m_shader(shader), m_camera(camera)
{
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

    m_vao = new Vao(vertices, sizeof(vertices), indices, sizeof(indices), GL_TRIANGLES, 6);
}

SpriteRenderer::~SpriteRenderer()
{
    delete m_vao;
}



void SpriteRenderer::draw()
{
    m_shader->bind();
    m_shader->uniform("u_ProjView", m_camera.getProjection() * m_camera.getView());

    for (size_t i = 0; i < m_sprites.size(); ++i)
    {
        draw(m_sprites[i]);
    }

    m_shader->unbind();
}


size_t SpriteRenderer::add(Sprite* sprite)
{
    static size_t counter = 0;
    counter++;

    m_sprites.push_back(RendererSprite(sprite, counter));
    return counter;
}

void SpriteRenderer::remove(const size_t& id)
{
    for (size_t i = 0; i < m_sprites.size(); ++i)
    {
        if (m_sprites[i].id == id)
        {
            m_sprites.erase(m_sprites.begin() + i);
        }
    }
}

void SpriteRenderer::draw(const RendererSprite& sprite)
{
    draw(*sprite.sprite);
}

void SpriteRenderer::draw(const Sprite& sprite)
{
    sprite.getTexture().bind();

    m_shader->uniform("u_Transform", sprite.getTransform());

    m_vao->bind();
    m_vao->draw();
    m_vao->unbind();


    sprite.getTexture().unbind();
}