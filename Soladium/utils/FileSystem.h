#pragma once

#include "Singleton.h"
#include <string>

class FileSystem sealed
{
	SINGLETON(FileSystem)

public:

	/// <summary>
	/// ������ ����� � �����. � ������ ������ ���������� ������ ������.
	/// </summary>
	std::string read(const char* path);

	// TODO: �������� ����������, �������������� ������, �������� ������ � ����������.
};