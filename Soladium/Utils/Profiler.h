#pragma once

#include <stack>
#include <chrono>
#include <string>


class Profiler sealed
{
public:

	struct ProfilerTask
	{
		ProfilerTask(const char* name, const std::chrono::steady_clock::time_point& start) : name(name), start(start) {}

		const char* name;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;

		void computeTime()
		{
			time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		}

		const std::string toString() const
		{
			return std::string(name).append(": ").append(std::to_string(time));
		}

		/// <summary>
		/// In seconds
		/// </summary>
		long long time;
	};

	Profiler();
	~Profiler();
	Profiler(const Profiler&) = delete;

	void start(const char* name);
	ProfilerTask end();
private:
	std::stack<ProfilerTask> m_Tasks;
};