#pragma once
#include "Component.h"
#include "../renderer/SpriteRenderer.h"

class SpriteRendererComponent sealed
	: public Component
{
public:
	SpriteRendererComponent(const Texture& texture, SpriteRenderer& spriteRenderer);
	~SpriteRendererComponent();

	void start() override;
	void update() override;
	void end() override;
private:
	const Texture& m_texture;
	Sprite* m_sprite;
	SpriteRenderer& m_spriteRenderer;

	size_t m_id;
};