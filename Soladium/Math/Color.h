#pragma once

#include <math.h>

typedef unsigned char BYTE_8;

#define FLOAT_TO_BYTE(f) (f >= 1.0f ? 255 : (f <= 0.0f ? 0 : (int)floorf(f * 256.0f)))
#define BYTE_TO_FLOAT(f) f*(1.f/255.f)

struct Color sealed
{
	BYTE_8 R, G, B;

	Color(const BYTE_8& r, const BYTE_8& g, const BYTE_8& b) : R(r), G(g), B(b) {}
	Color(const Color& copy) : R(copy.R), G(copy.G), B(copy.B) {}

	Color(const float& r, const float& g, const float& b)
		: R(FLOAT_TO_BYTE(r)), G(FLOAT_TO_BYTE(g)), B(FLOAT_TO_BYTE(b)) { }

};