#include "Profiler.h"

Profiler::Profiler()
{

}

Profiler::~Profiler()
{

}

void Profiler::begin(const char* name)
{
    m_tasks.push(Task(name, glfwGetTime()));
}

Profiler::Task Profiler::end()
{
    m_tasks.top().end(glfwGetTime());
    Task ret(m_tasks.top());
    m_tasks.pop();
    return ret;
}
