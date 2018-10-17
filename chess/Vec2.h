#pragma once
class Vec2
{
public:
	Vec2();
	Vec2(int _i, int _j);
	~Vec2();
	int i;
	int j;
	Vec2 operator+(const Vec2& v);
	Vec2 operator-(const Vec2& v);
	Vec2 operator*(const Vec2& v);
	Vec2 operator/(const Vec2& v);
	Vec2 operator+=(const Vec2& v);
	Vec2 operator-=(const Vec2& v);
	bool operator==(const Vec2& v);
};