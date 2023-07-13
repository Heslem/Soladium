#pragma once
#include "Singleton.h"
#include <stack>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Профайлер не идеален!

class Profiler sealed
{
	SINGLETON(Profiler)

public:
	class Task sealed
	{
	public:
		Task(const char* name, const double& start)
			: m_name(name), m_start(start), m_end(0.0), m_elapsed(0.0) {}
		~Task() = default;

		void end(const double& end) { m_end = end; m_elapsed = m_end - m_start; }
		
		double getInSeconds() const { return m_elapsed; }
		double getInMilliseconds() const { return m_elapsed * 1000.0; }
		double getInMicroseconds() const { return m_elapsed * 1000000.0; }

	private:
		const char* m_name;
		double m_start;
		double m_end;

		double m_elapsed;
	};

private:

	std::stack<Task> m_tasks;
public:
	
	void begin(const char* name);
	Task end();
};