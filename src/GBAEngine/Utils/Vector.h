#pragma once
#include <cmath>
class Vector2
{
public:
	float x;
	float y;
	Vector2()
		: x(0.0f), y(0.0f) {}
	Vector2(float _x, float _y)
		: x(_x), y(_y) {}
	void Normalize() {
	
		float length = sqrt(x * x + y * y);
		x /= length;
		y /= length;
	}
	Vector2 GetNormalizedVector() {
		float length = sqrt(x * x + y * y);
		return Vector2(x / length, y / length);
	}
	float Distance(Vector2* other) {
		return sqrt((x - other->x) * (x - other->x) + (y - other->y) * (y - other->y));
	}
	inline Vector2 const operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}
	inline Vector2 const operator-(const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}
	inline Vector2 const operator*(const float& other) const {
		return Vector2(x * other, y * other);
	}
	inline Vector2 const operator*(const Vector2& other) const {
		return Vector2(x * other.x, y * other.y);
	}
	inline Vector2 const operator/(const float& other) const {
		return Vector2(x / other, y / other);
	}
	
	inline Vector2 const operator+(const Vector3& other) const {
		return Vector2(x + other.x, y + other.y);
	}
	inline Vector2 const operator-(const Vector3& other) const {
		return Vector2(x - other.x, y - other.y);
	}
	inline Vector2 const operator*(const Vector3& other) const {
		return Vector2(x * other.x, y * other.y);
	}
};
class Vector3 : Vector2
{
public:
    float z;
	Vector3(){x = 0.0f; y = 0.0f; z = 0.0f;}
	Vector3(float _x, float _y, float _z){x = _x; y = _y; z = _z;}
	void Normalize() {
		float length = sqrt(x * x + y * y + z * z);
		x /= length;
		y /= length;
		z /= length;
	}
	Vector3 GetNormalizedVector() {
		float length = sqrt(x * x + y * y + z * z);
		return Vector3(x / length, y / length, z / length);
	}
	float Distance(Vector3* other) {
		return sqrt((x - other->x) * (x - other->x) + (y - other->y) * (y - other->y) + (z - other->z) * (z - other->z));
	}
	inline Vector3 const operator+(const Vector3& other) const {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}
	inline Vector3 const operator-(const Vector3& other) const {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}
	inline Vector3 const operator*(const float& other) const {
		return Vector3(x * other, y * other, z * other);
	}
	inline Vector3 const operator*(const Vector3& other) const {
		return Vector3(x * other.x, y * other.y, z * other.z);
	}
	inline Vector3 const operator/(const float& other) const {
		return Vector3(x / other, y / other, z / other);
	}	

	//Vector2 operators
	inline Vector3 const operator+(const Vector2& other) const {
		return Vector3(x + other.x, y + other.y, z);
	}
	inline Vector3 const operator-(const Vector2& other) const {
		return Vector3(x - other.x, y - other.y, z);
	}
	inline Vector3 const operator*(const Vector2& other) const {
		return Vector3(x * other.x, y * other.y, z);
	}
};

