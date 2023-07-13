#include "SpriteComponent.h"
#include "../../Engine.h"

core::component::SpriteComponent::SpriteComponent(renderer::Sprite* sprite)
	: Component("sprite"), m_sprite(sprite), m_id(0)
{
}

core::component::SpriteComponent::~SpriteComponent()
{
	delete m_sprite;
}

void core::component::SpriteComponent::begin()
{
	// TODO: слишком длинное получение spriteRenderer
	m_id = Engine::getInstance().getSpriteRenderer().add(m_sprite);
}

void core::component::SpriteComponent::update()
{
}

void core::component::SpriteComponent::end()
{
	Engine::getInstance().getSpriteRenderer().remove(m_id);
}
