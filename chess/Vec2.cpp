#include "Vec2.h"
#include <iostream>
Vec2::Vec2() :i(-1), j(-1) {}

Vec2::Vec2(int _i, int _j)
	:i(_i), j(_j)
{
}

Vec2::Vec2(const Vec2& v)
	:i(v.i), j(v.j)
{
}

Vec2::~Vec2()
{
}


Vec2 Vec2::operator+(const Vec2& v) const { return Vec2(i + v.i, j + v.j);}
Vec2 Vec2::operator-(const Vec2& v) const { return Vec2(i - v.i, j - v.j); }
Vec2 Vec2::operator*(const Vec2& v) const { return Vec2(i * v.i, j * v.j); }
Vec2 Vec2::operator*(int n) const { return Vec2(i * n, j * n); }
Vec2 Vec2::operator/(const Vec2& v) const { return Vec2(i / v.i, j / v.j); }
Vec2& Vec2::operator+=(const Vec2& v) { i += v.i; j += v.j; return *this; }
Vec2& Vec2::operator-=(const Vec2& v) { i -= v.i; j -= v.j; return *this; }
Vec2& Vec2::operator/=(const Vec2& v) { i /= v.i; j /= v.j; return *this; }
Vec2& Vec2::operator*=(const Vec2& v) { i *= v.i; j *= v.j; return *this; }
Vec2& Vec2::operator*=(int n) { i *= n; j *= n; return *this; }
Vec2& Vec2::operator=(const Vec2& v)
 { 
	i = v.i; j = v.j; return *this;
}
bool Vec2::operator==(const Vec2& v) const
{ 
	if (i == v.i && j == v.j) 
		return true; 
	else 
		return false; 
}
bool Vec2::operator!=(const Vec2& v) const
{
	return (!(*this == v));
}
int Vec2::operator[](const int& n)
{
	if (n == 0)
		return i;
	else if (n == 1)
		return j;
	else
	{
		std::cout << "Illegal indexing of Vec2, returning i" << std::endl;
		return i;
	}
}

std::ostream &operator<<(std::ostream &output, const Vec2& v)
{
	output << "(" << v.i << ", " << v.j << ")";
	return output;
}
