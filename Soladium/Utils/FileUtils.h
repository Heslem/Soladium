#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <streambuf>
#include <sstream>


static std::string readFile(const char* path) {
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cout << "Could not open the file - '" << path << "'" << std::endl;
        return std::string("");
    }
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}