#include "Profiler.h"

Profiler::Profiler()
{
}

Profiler::~Profiler()
{
}

void Profiler::start(const char* name)
{
	m_Tasks.push(ProfilerTask(name, std::chrono::high_resolution_clock::now()));
}

Profiler::ProfilerTask Profiler::end()
{
	ProfilerTask temp(m_Tasks.top());
	m_Tasks.pop();

	temp.end = std::chrono::high_resolution_clock::now();
	temp.computeTime();
	return temp;
}
