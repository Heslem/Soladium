#include "SpriteRendererComponent.h"

#include "TransformComponent.h"
#include "GameObject.h"

SpriteRendererComponent::SpriteRendererComponent(const Texture& texture, SpriteRenderer& spriteRenderer)
	: Component("SpriteRenderer"), m_texture(texture), m_spriteRenderer(spriteRenderer)
{
}

SpriteRendererComponent::~SpriteRendererComponent()
{
}

void SpriteRendererComponent::start()
{
	m_sprite = new Sprite(m_texture, m_gameObject->getComponent<TransformComponent>("Transform")->getTransform());
	m_id = m_spriteRenderer.add(m_sprite);
}

void SpriteRendererComponent::update()
{
}

void SpriteRendererComponent::end()
{
	m_spriteRenderer.remove(m_id);
}
