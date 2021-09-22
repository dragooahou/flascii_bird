#pragma once

#include <math.h>

class Vector2 {

public:
	float x;
	float y;

    Vector2() : x(0), y(0) {

    }

	Vector2(float x, float y) : x(x), y(y) {

	}

	Vector2 operator + (const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2& operator += (const Vector2& other) {
		x + other.x; y + other.y;
		return *this;
	}

	Vector2 operator - (const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator * (float scalar) const {
		return Vector2(x * scalar, y * scalar);
	}

	float operator * (const Vector2& other) const {
		return (x * other.y) + (y * other.x);
	}

	float Distance(const Vector2& vector1, const Vector2& vector2) const {
		return sqrt(((vector1.x - vector2.x) * (vector1.x - vector2.x)) + ((vector1.y - vector2.y) * (vector1.y - vector2.y)));
	}

};