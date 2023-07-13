#include "Log.h"
#include <Windows.h>
#include <unordered_map>

void* Log::s_consoleHandle;

void Log::init()
{
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Log::message(const std::string& str, const unsigned short& color)
{
	SetConsoleTextAttribute(s_consoleHandle, color);
	std::cout << "[LOG] " << str << std::endl;
	SetConsoleTextAttribute(s_consoleHandle, 7);

}

void Log::warn(const std::string& str)
{
	SetConsoleTextAttribute(s_consoleHandle, 14);
	std::cout << "[WARN] " << str << std::endl;
	SetConsoleTextAttribute(s_consoleHandle, 7);
}

void Log::error(const std::string& str)
{
	SetConsoleTextAttribute(s_consoleHandle, 12);
	std::cout << "[ERROR] " << str << std::endl;
	SetConsoleTextAttribute(s_consoleHandle, 7);
}

void Log::errorOnce(const std::string& str)
{
	// Hmmm, maybe this right solution or not.
	static const std::hash<std::string> hasher;
	static std::vector<size_t> cache;

	size_t hash = hasher(str);
	for (size_t i = 0; i < cache.size(); ++i)
		if (cache[i] == hash)
			return;

	cache.push_back(hash);
	error(str);
}
