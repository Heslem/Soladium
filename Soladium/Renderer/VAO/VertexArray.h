#pragma once
#include <vector>
#include "Vertex.h"
struct VertexArray {
public:

	void addVertex(const Vertex& vertex);
private:
	std::vector<Vertex> m_Vertices;
};