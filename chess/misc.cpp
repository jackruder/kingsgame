#include "misc.h"

std::vector<Coord> startpos = { Coord::a1,Coord::h1,Coord::c1,Coord::f1,Coord::b1,Coord::g1,Coord::e1,Coord::d1,
								Coord::a2,Coord::b2,Coord::c2,Coord::d2,Coord::e2,Coord::f2,Coord::g2,Coord::h2,
								Coord::a7,Coord::h7,Coord::c7,Coord::f7,Coord::b7,Coord::g7,Coord::e7,Coord::d7,
								Coord::a8,Coord::b8,Coord::c8,Coord::d8,Coord::e8,Coord::f8,Coord::g8,Coord::h8, };
int toIndex(Vec2 a)
{
	int b = (8 * a[1] + a[0]);
	return b;
}


Vec2 toCoord(int i)
{
	int a_x = i % 8;  //finds file value
	int a_y = (i - a_x) / 8; //finds row value

	Vec2 a = Vec2(a_x, a_y);

	return a;
}

Vec2 toCoord(Coord c)
{
	int i = static_cast<int>(c);
	int a_x = i % 8;  //finds file value
	int a_y = (i - a_x) / 8; //finds row value

	Vec2 a = Vec2(a_x, a_y);

	return a;
}

bool onBoard(int f, int r)
{
	if (f >= 0 && f < 8 && r >= 0 && r < 8) 
		return true;
	else
		return false;
}

bool onBoard(Vec2 pos)
{
	int f = pos[0];
	int r = pos[1];
	if (f >= 0 && f < 8 && r < 8 && r >= 0) {
		return true;
	}
	else {
		return false;
	}
}