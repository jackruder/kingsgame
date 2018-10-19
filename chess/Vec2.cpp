#include "Vec2.h"

Vec2::Vec2() :i(-1), j(-1) {}

Vec2::Vec2(int _i, int _j)
	:i(_i), j(_j)
{
}


Vec2::~Vec2()
{
}


Vec2 Vec2::operator+(const Vec2& v) {return Vec2(i + v.i, j + v.j);}
Vec2 Vec2::operator-(const Vec2& v) { return Vec2(i - v.i, j - v.j); }
Vec2 Vec2::operator*(const Vec2& v) { return Vec2(i * v.i, j * v.j); }
Vec2 Vec2::operator/(const Vec2& v) { return Vec2(i / v.i, j / v.j); }
Vec2 Vec2::operator+=(const Vec2& v) { return Vec2(i += v.i, j += v.j); }
Vec2 Vec2::operator-=(const Vec2& v) { return Vec2(i -= v.i, j -= v.j); }
Vec2 Vec2::operator/=(const Vec2& v) { return Vec2(i /= v.i, j /= v.j); }
Vec2 Vec2::operator*=(const Vec2& v) { return Vec2(i *= v.i, j *= v.j); }

bool Vec2::operator==(const Vec2& v) 
{ 
	if (i == v.i && j == v.j) 
		return true; 
	else 
		return false; 
}
int& Vec2::operator[](const int& n)
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

const int& Vec2::operator[](const int& n) const
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