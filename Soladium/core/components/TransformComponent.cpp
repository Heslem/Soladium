#include "TransformComponent.h"

#include "../../Engine.h"
core::component::TransformComponent::TransformComponent()
	: Component("transform"), m_transform(1.0f)
{
}

core::component::TransformComponent::~TransformComponent()
{
}

void core::component::TransformComponent::begin()
{
}

void core::component::TransformComponent::update()
{
}

void core::component::TransformComponent::end()
{
}

void core::component::TransformComponent::move(const float& x, const float& y, const float& z)
{
	m_transform = glm::translate(m_transform, glm::vec3(x, y, z));
}

void core::component::TransformComponent::scale(const float& x, const float& y, const float& z)
{
	m_transform = glm::scale(m_transform, glm::vec3(x, y, z));
}
