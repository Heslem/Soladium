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

void SpriteRenderer::draw(const Sprite& sprite)
{
    sprite.getTexture().bind();

    m_shader->bind();

    m_shader->uniform("u_Transform", sprite.getTransform());
    m_shader->uniform("u_ProjView", m_camera.getProjection() * m_camera.getView());

    m_vao->bind();
    m_vao->draw();
    m_vao->unbind();

    m_shader->unbind();

    sprite.getTexture().unbind();
}
