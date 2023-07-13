#pragma once

#include "../renderer/vao/Vao.h"

class VaoGenerator sealed
{
private:
	VaoGenerator() = default;
	VaoGenerator(const VaoGenerator&) = delete;
public:
	~VaoGenerator() = default;

	static renderer::Vao* generateSquare();
};