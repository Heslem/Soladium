#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

renderer::Texture::Texture(const char* path)
    : m_pixels(nullptr), m_id(0), m_width(0), m_height(0)
{
    stbi_set_flip_vertically_on_load(1);
    m_pixels = stbi_load(path, &m_width, &m_height, &m_bpp, 4);

    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)m_pixels);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (m_pixels)
        stbi_image_free(m_pixels);
}

renderer::Texture::~Texture()
{
    glDeleteTextures(1, &m_id);
}

void renderer::Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void renderer::Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
