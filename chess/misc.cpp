#include "misc.h"


	extern std::vector<std::string> sCoords = {
	"a1","b1","c1","d1","e1","f1","g1","h1",
	"a2","b2","c2","d2","e2","f2","g2","h2",
	"a3","b3","c3","d3","e3","f3","g3","h3",
	"a4","b4","c4","d4","e4","f4","g4","h4",
	"a5","b5","c5","d5","e5","f5","g5","h5",
	"a6","b6","c6","d6","e6","f6","g6","h6",
	"a7","b7","c7","d7","e7","f7","g7","h7",
	"a8","b8","c8","d8","e8","f8","g8","h8"
};

std::vector<Coord> startpos = { Coord::a1,Coord::h1,Coord::c1,Coord::f1,Coord::b1,Coord::g1,Coord::e1,Coord::d1,
								Coord::a2,Coord::b2,Coord::c2,Coord::d2,Coord::e2,Coord::f2,Coord::g2,Coord::h2,
								Coord::a8,Coord::h8,Coord::c8,Coord::f8,Coord::b8,Coord::g8,Coord::e8,Coord::d8,
								Coord::a7,Coord::b7,Coord::c7,Coord::d7,Coord::e7,Coord::f7,Coord::g7,Coord::h7 };

std::map<std::string, Coord> cMap = {
{"a1",Coord::a1}, {"b1",Coord::b1}, {"c1",Coord::c1}, {"d1",Coord::d1}, {"e1",Coord::e1}, {"f1",Coord::f1}, {"g1",Coord::g1}, {"h1",Coord::h1},
{"a2",Coord::a2}, {"b2",Coord::b2}, {"c2",Coord::c2}, {"d2",Coord::d2}, {"e2",Coord::e2}, {"f2",Coord::f2}, {"g2",Coord::g2}, {"h2",Coord::h2},
{"a3",Coord::a3}, {"b3",Coord::b3}, {"c3",Coord::c3}, {"d3",Coord::d3}, {"e3",Coord::e3}, {"f3",Coord::f3}, {"g3",Coord::g3}, {"h3",Coord::h3},
{"a4",Coord::a4}, {"b4",Coord::b4}, {"c4",Coord::c4}, {"d4",Coord::d4}, {"e4",Coord::e4}, {"f4",Coord::f4}, {"g4",Coord::g4}, {"h4",Coord::h4},
{"a5",Coord::a5}, {"b5",Coord::b5}, {"c5",Coord::c5}, {"d5",Coord::d5}, {"e5",Coord::e5}, {"f5",Coord::f5}, {"g5",Coord::g5}, {"h5",Coord::h5},
{"a6",Coord::a6}, {"b6",Coord::b6}, {"c6",Coord::c6}, {"d6",Coord::d6}, {"e6",Coord::e6}, {"f6",Coord::f6}, {"g6",Coord::g6}, {"h6",Coord::h6},
{"a7",Coord::a7}, {"b7",Coord::b7}, {"c7",Coord::c7}, {"d7",Coord::d7}, {"e7",Coord::e7}, {"f7",Coord::f7}, {"g7",Coord::g7}, {"h7",Coord::h7},
{"a8",Coord::a8}, {"b8",Coord::b8}, {"c8",Coord::c8}, {"d8",Coord::d8}, {"e8",Coord::e8}, {"f8",Coord::f8}, {"g8",Coord::g8}, {"h8",Coord::h8}
};

std::map<std::string, Pname> pMap = {
	{"wrook1", Pname::wrook1},
	{"wrook2", Pname::wrook2},
	{"wbishop1", Pname::wbishop1},
	{"wbishop2", Pname::wbishop2},
	{"wknight1", Pname::wknight1},
	{"wknight2", Pname::wknight2},
	{"wking1", Pname::wking1},
	{"wqueen1", Pname::wqueen1},
	{"wpawn1", Pname::wpawn1},
	{"wpawn2", Pname::wpawn2},
	{"wpawn3", Pname::wpawn3},
	{"wpawn4", Pname::wpawn4},
	{"wpawn5", Pname::wpawn5},
	{"wpawn6", Pname::wpawn6},
	{"wpawn7", Pname::wpawn7},
	{"wpawn8", Pname::wpawn8},
	{"brook1", Pname::brook1},
	{"brook2", Pname::brook2},
	{"bbishop1", Pname::bbishop1},
	{"bbishop2", Pname::bbishop2},
	{"bknight1", Pname::bknight1},
	{"bknight2", Pname::bknight2},
	{"bking1", Pname::bking1},
	{"bqueen1", Pname::bqueen1},
	{"bpawn1", Pname::bpawn1},
	{"bpawn2", Pname::bpawn2},
	{"bpawn3", Pname::bpawn3},
	{"bpawn4", Pname::bpawn4},
	{"bpawn5", Pname::bpawn5},
	{"bpawn6", Pname::bpawn6},
	{"bpawn7", Pname::bpawn7},
	{"bpawn8", Pname::bpawn8}

};

int toIndex(Vec2 a)
{
	return  (8 * a[1] + a[0]);
}

Coord toCoord(Vec2 a)
{
	int b = (8 * a[1] + a[0]);
	return static_cast<Coord>(b);
}

Vec2 toVec(int i)
{
	int a_x = i % 8;  //finds file value
	int a_y = (i - a_x) / 8; //finds row value

	Vec2 a = Vec2(a_x, a_y);

	return a;
}

Vec2 toVec(Coord c)
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


