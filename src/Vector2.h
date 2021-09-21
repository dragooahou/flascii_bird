#pragma once

#include <math.h>

class Vector2 {

private:
	float x;
	float y;

public:

	Vector2(float x, float y) : x(x), y(y) {

	}

	Vector2 operator + (Vector2 other) {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator - (Vector2 other) {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator * (float scalar) {
		return Vector2(x * scalar, y * scalar);
	}

	float operator * (Vector2 other) {
		return (x * other.y) + (y * other.x);
	}

	float Distance(Vector2 vector1, Vector2 vector2) {
		return sqrt(((vector1.x - vector2.x) * (vector1.x - vector2.x)) + ((vector1.y - vector2.y) * (vector1.y - vector2.y)));
	}

};