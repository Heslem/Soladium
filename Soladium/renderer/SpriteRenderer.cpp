#include "SpriteRenderer.h"
#include "../utils/VaoGenerator.h"

#include "../utils/Profiler.h"
#include <iostream>

void renderer::SpriteRenderer::render(const Sprite& sprite)
{
    sprite.texture->bind();
    m_shader->uniform("u_Transform", sprite.transform);

    m_vao->render();

    sprite.texture->unbind();
}

renderer::SpriteRenderer::SpriteRenderer()
{
    m_vao = VaoGenerator::generateSquare();
}

renderer::SpriteRenderer::~SpriteRenderer()
{
    delete m_vao;
}

size_t renderer::SpriteRenderer::add(Sprite* sprite)
{
    // TODO: плохой вариант счётчика
    static size_t counter = 0;
    m_sprites.push_back(new rendererSprite(sprite, counter));
    counter++;
    return counter;
}

void renderer::SpriteRenderer::remove(const size_t& id)
{
    for (size_t i = 0; i < m_sprites.size(); ++i)
    {
        if (m_sprites[i]->id == id)
        {
            m_sprites.erase(m_sprites.begin() + i);
            break;
        }
    }
}

void renderer::SpriteRenderer::render()
{
    m_shader->bind();
    m_shader->uniform("u_ProjView", m_camera->getProjection() * m_camera->getView());

    m_vao->bind();
    for (size_t i = 0; i < m_sprites.size(); ++i)
    {
        render(*m_sprites[i]->sprite);
    }
    m_vao->unbind();

    m_shader->unbind();
}

void renderer::SpriteRenderer::setShader(Shader* shader)
{
    m_shader = shader;
}

void renderer::SpriteRenderer::setCamera(Camera* camera)
{
    m_camera = camera;
}
