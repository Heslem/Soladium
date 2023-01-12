#pragma once

#include <math.h>

template<typename Type>
struct Vector2 sealed
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(const Type& x, const Type& y) : x(x), y(y) {}
	Vector2(const Vector2& copy) : x(copy.x), y(copy.y) {}
	~Vector2() {};

	Type x;
	Type y;

	Type distance(const Vector2& a, const Vector2& b) {
		return sqrtf(powf(b.x - a.x, 2.0f) + powf(b.y - a.y, 2.0f));
	}

	Vector2<Type> lerp(const Vector2<Type>& a, const Vector2<Type>& b, const float& damping) {
		float temp = damping;
		if (temp > 1.0F) {
			temp = 1.0F;
		}
		else if (damping < 0.0F) {
			temp = 1.0F;
		}

		return Vector2<Type>(
			a.x + (b.x - a.x) * temp,
			a.y + (b.y - a.y) * temp
		);
	}
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;
typedef Vector2<double> Vector2d;