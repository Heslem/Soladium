#include "MonoComponent.h"

MonoComponent::MonoComponent(BaseMonoComponentData data, MonoObject* object)
	: m_data(data), m_object(object)
	
{
}

MonoComponent::~MonoComponent()
{
}

void MonoComponent::start()
{
	mono_runtime_invoke(m_data.startMethod, m_object, nullptr, NULL);
}

void MonoComponent::update()
{
	mono_runtime_invoke(m_data.updateMethod, m_object, nullptr, NULL);
}
