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
	Vec2 operator+(const Vec2& v) const;
	Vec2 operator-(const Vec2& v) const;
	Vec2 operator*(const Vec2& v) const;
	Vec2 operator*(int n) const;
	Vec2 operator/(const Vec2& v) const;
	Vec2& operator+=(const Vec2& v);
	Vec2& operator-=(const Vec2& v);
	Vec2& operator*=(const Vec2& v);
	Vec2& operator*=(int n);
	Vec2& operator/=(const Vec2& v);
	bool operator==(const Vec2& v) const;
	bool operator!=(const Vec2 & v) const;
	int operator[](const int& n); 
	friend std::ostream& operator<<(std::ostream &output, const Vec2& v);

};