#pragma once


template<typename Type>
struct Vector3 sealed
{
public:
	Vector3() : x(0), y(0), z(0) {}
	Vector3(const Type& x, const Type& y, const Type& z) : x(x), y(y), z(z) {}
	Vector3(const Vector2& copy) : x(copy.x), y(copy.y), z(copy.z) {}
	~Vector3() {};

	Type x;
	Type y;
	Type z;
};

typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;
typedef Vector3<double> Vector3d;