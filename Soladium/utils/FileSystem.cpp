#include "FileSystem.h"

#include <fstream>
#include <iostream>
#include <streambuf>
#include <sstream>

#include "Log.h"

FileSystem::FileSystem()
{

}

FileSystem::~FileSystem()
{

}

std::string FileSystem::read(const char* path)
{
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        Log::error(std::string("Could not open the file -") + path);
        return std::string("");
    }
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}
