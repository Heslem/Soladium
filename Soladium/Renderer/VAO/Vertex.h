#pragma once

#include "../../Math/Vector2.h"
#include "../../Math/Vector3.h"
#include "../../Math/Color.h"

struct Vertex
{
	Vertex(const Vector2f& position) : position(position), uv(0, 0), color(1.0F, 1.0F, 1.0F) {}
	Vertex(const Vector2f& position, const Vector2f& uv) : position(position), uv(uv), color(1.0F, 1.0F, 1.0F) {}
	Vertex(const Vector2f& position, const Vector2f& uv, const Color& color) : position(position), uv(uv), color(color) {}

	Vector2f position;
	Vector2f uv;
	Color color;
};