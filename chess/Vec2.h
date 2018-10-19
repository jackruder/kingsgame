#pragma once
#include <iostream>
class Vec2
{
public:
	int i;
	int j;
	Vec2();
	Vec2(int _i, int _j);
	~Vec2();
	Vec2 operator+(const Vec2& v);
	Vec2 operator-(const Vec2& v);
	Vec2 operator*(const Vec2& v);
	Vec2 operator/(const Vec2& v);
	Vec2 operator+=(const Vec2& v);
	Vec2 operator-=(const Vec2& v);
	Vec2 operator*=(const Vec2& v);
	Vec2 operator/=(const Vec2& v);
	bool operator==(const Vec2& v);
	int& operator[](const int& n); 
	const int& operator[](const int& n) const
};