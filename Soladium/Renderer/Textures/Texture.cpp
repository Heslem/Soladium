#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const char* path)
    : m_Pixels(nullptr), m_Id(0), m_Width(0), m_Height(0)
{
    stbi_set_flip_vertically_on_load(1);
    m_Pixels = stbi_load(path, &m_Width, &m_Height, &m_Bpp, 4);

    glGenTextures(1, &m_Id);
    glBindTexture(GL_TEXTURE_2D, m_Id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)m_Pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    if (m_Pixels)
        stbi_image_free(m_Pixels);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_Id);
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, m_Id);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
