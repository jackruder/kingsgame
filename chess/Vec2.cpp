#include "Vec2.h"

Vec2::Vec2(){}

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
bool Vec2::operator==(const Vec2& v) { if (i == v.i && j == v.j) return true; else return false; }
