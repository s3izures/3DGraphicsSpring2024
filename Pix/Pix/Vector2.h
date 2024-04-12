#pragma once

typedef struct Vector2
{
	float x;
	float y;

	constexpr Vector2() : x(0), y(0) {}
	constexpr Vector2(float _s) : x(_s), y(_s){}
	constexpr Vector2(float _x, float _y) : x(_x),y(_y){}

	Vector2 operator+(float s)const { return { x + s, y + s }; }
	Vector2 operator-(float s)const { return { x - s, y - s }; }
	Vector2 operator*(float s)const { return { x * s, y * s }; }
	Vector2 operator/(float s)const { return { x / s, y / s }; }
	Vector2 operator+(const Vector2& res)const { return { x + res.x, y + res.y }; }
	Vector2 operator-(const Vector2& res)const { return { x - res.x, y - res.y }; }
	Vector2 operator*(const Vector2& res)const { return { x * res.x, y * res.y }; }
	Vector2 operator/(const Vector2& res)const { return { x / res.x, y / res.y }; }

	Vector2& operator+=(float s) { x += s, y += s; return *this; }
	Vector2& operator-=(float s) { x -= s, y -= s; return *this; }
	Vector2& operator*=(float s) { x *= s, y *= s; return *this; }
	Vector2& operator/=(float s) { x /= s, y /= s; return *this; }
	Vector2& operator+=(const Vector2& res) { x += res.x, y += res.y; return *this; }
	Vector2& operator-=(const Vector2& res) { x -= res.x, y -= res.y; return *this; }
	Vector2& operator*=(const Vector2& res) { x *= res.x, y *= res.y; return *this; }
	Vector2& operator/=(const Vector2& res) { x /= res.x, y /= res.y; return *this; }
}Vector2;