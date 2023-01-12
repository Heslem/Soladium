#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>

static std::string readFile(const char* path) {
   
    std::ifstream t(path);
    std::string str;

    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());
    return str;
}