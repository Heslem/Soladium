#pragma once

#include "Singleton.h"
#include <string>

class FileSystem sealed
{
	SINGLETON(FileSystem)

public:

	/// <summary>
	/// Читает текст с файла. В случае ошибки возвращает пустую строку.
	/// </summary>
	std::string read(const char* path);

	// TODO: Создание директорий, редактирование файлов, удаление файлов и директорий.
};