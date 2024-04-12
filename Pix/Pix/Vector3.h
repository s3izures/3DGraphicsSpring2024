#pragma once

typedef struct Vector3
{
	float x;
	float y;
	float z;

	constexpr Vector3() : x(0), y(0), z(0) {}
	constexpr Vector3(float _s) : x(_s), y(_s), z(_s) {}
	constexpr Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	Vector3 operator+(float s)const { return { x + s, y + s, z + s}; }
	Vector3 operator-(float s)const { return { x - s, y - s , z - s }; }
	Vector3 operator*(float s)const { return { x * s, y * s, z * s }; }
	Vector3 operator/(float s)const { return { x / s, y / s, z / s }; }
	Vector3 operator+(const Vector3& res)const { return { x + res.x, y + res.y, z + res.z }; }
	Vector3 operator-(const Vector3& res)const { return { x - res.x, y - res.y, z - res.z }; }
	Vector3 operator*(const Vector3& res)const { return { x * res.x, y * res.y, z * res.z }; }
	Vector3 operator/(const Vector3& res)const { return { x / res.x, y / res.y, z / res.z }; }

	Vector3& operator+=(float s) { x += s, y += s, z += s; return *this; }
	Vector3& operator-=(float s) { x -= s, y -= s, z -= s; return *this; }
	Vector3& operator*=(float s) { x *= s, y *= s, z *= s; return *this; }
	Vector3& operator/=(float s) { x /= s, y /= s, z /= s; return *this; }
	Vector3& operator+=(const Vector3& res) { x += res.x, y += res.y, z += res.z; return *this; }
	Vector3& operator-=(const Vector3& res) { x -= res.x, y -= res.y, z -= res.z; return *this; }
	Vector3& operator*=(const Vector3& res) { x *= res.x, y *= res.y, z *= res.z; return *this; }
	Vector3& operator/=(const Vector3& res) { x /= res.x, y /= res.y, z/= res.z; return *this; }

}Vector3;