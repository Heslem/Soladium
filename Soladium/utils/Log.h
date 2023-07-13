#pragma once

#include <iostream>
#include <string>

class Log
{
	friend class Engine;
private:
	static void* s_consoleHandle;

	/// <summary>
	/// Подключается к консоли. (для изменения цвета текста)
	/// </summary>
	static void init();
public:

	static void message(const std::string& str, const unsigned short& color = 7);
	static void warn(const std::string& str);
	static void error(const std::string& str);

	/// <summary>
	/// Выводит ошибку один раз.
	/// </summary>
	static void errorOnce(const std::string& str);
};