#include "TransformComponent.h"

TransformComponent::TransformComponent()
	: Component("Transform"), m_transform(1.0f)
{
}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::start()
{
}

void TransformComponent::update()
{
}

void TransformComponent::end()
{
}

void TransformComponent::move(const float& x, const float& y)
{
	m_transform = glm::translate(m_transform, glm::vec3(x, y, 0.0f));
}

void TransformComponent::scale(const float& x, const float& y)
{
	m_transform = glm::scale(m_transform, glm::vec3(x, y, 1.0f));
}
