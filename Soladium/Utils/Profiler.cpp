#include "Profiler.h"

Profiler::Profiler()
{
}

Profiler::~Profiler()
{
}

void Profiler::start(const char* name)
{
	m_Tasks.push(new ProfilerTask(name, std::chrono::high_resolution_clock::now()));
}

Profiler::ProfilerTask* Profiler::end()
{
	ProfilerTask* temp = m_Tasks.top();
	m_Tasks.pop();

	temp->computeTime(std::chrono::high_resolution_clock::now());
	return temp;
}
