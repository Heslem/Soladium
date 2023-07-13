#pragma once

#include "../Component.h"
#include "../../renderer/Sprite.h"

namespace core
{
	namespace component
	{
		/// <summary>
		/// Компонент для рендера спрайтов (автоматически удалит спрайт)
		/// </summary>
		class SpriteComponent sealed
			: public Component
		{
			renderer::Sprite* m_sprite;
			size_t m_id;
		public:
			SpriteComponent(renderer::Sprite* sprite);
			~SpriteComponent();

			void begin() override;
			void update() override;
			void end() override;
		};
	}
}