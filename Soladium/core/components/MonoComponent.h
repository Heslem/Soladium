#pragma once
#include "../Component.h"
#include "../../script/ScriptClass.h"

namespace core
{
	namespace component
	{
		class MonoComponent sealed
			: public Component
		{
			script::ScriptClass& m_scriptClass;

			/// <summary>
			/// ����� GameObject � SoladuimAPI
			/// </summary>
			MonoObject* m_monoGameObject;

			/// <summary>
			/// ��� ����� ���������
			/// </summary>
			MonoObject* m_object;

		public:
			MonoComponent(script::ScriptClass& scriptClass, MonoObject* object);
			~MonoComponent();

			void begin() override;
			void update() override;
			void end() override;

		private:
			friend class ScriptEngine;

			// TODO: delete
			friend class Engine;
		};
	}
}