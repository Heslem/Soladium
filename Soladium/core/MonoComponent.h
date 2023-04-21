#pragma once

#include "Component.h"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

class MonoComponent sealed
	: public Component
{
public:
	struct BaseMonoComponentData
	{
		BaseMonoComponentData() = delete;
		BaseMonoComponentData(MonoMethod* start, MonoMethod* update) : startMethod(start), updateMethod(update) {}

		MonoMethod* startMethod;
		MonoMethod* updateMethod;
	};

public:
	MonoComponent(BaseMonoComponentData data, MonoObject* object);
	MonoComponent(const MonoComponent&) = delete;
	~MonoComponent();

	void start() override;
	void update() override;
private:
	
	BaseMonoComponentData m_data;
	MonoObject* m_object;
};