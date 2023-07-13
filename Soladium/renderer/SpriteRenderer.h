#pragma once

#include <vector>
#include "Sprite.h"
#include "shaders/Shader.h"
#include "cameras/Camera.h"

namespace renderer
{
	class SpriteRenderer sealed
	{
		SpriteRenderer(const SpriteRenderer&) = delete;

		struct rendererSprite
		{
			rendererSprite(Sprite* s, const size_t& i) : sprite(s), id(i) {}

			Sprite* sprite;
			const size_t id;
		}; 

		std::vector<rendererSprite*> m_sprites;
		Shader* m_shader;
		Camera* m_camera;

		Vao* m_vao;

		void render(const Sprite& sprite);
	public:
		SpriteRenderer();
		~SpriteRenderer();

		/// <summary>
		/// Добавляет спрайт к рендеру, возвращая ID.
		/// </summary>
		size_t add(Sprite* sprite);

		void remove(const size_t& id);
		
		void render();

		void setShader(Shader* shader);
		void setCamera(Camera* camera);
	};
}