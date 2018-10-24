#include "misc.h"

std::vector<int> startpos = { 0,7,2,5,1,6,5,4,8,9,10,11,12,13,14,15,56,63,58,61,57,62,60,59,48,49,50,51,52,53,54,55 };
int toIndex(Vec2 a)
{
	int b = (8 * a[1] + a[0]);
	return b;
}


Vec2 toCoord(int i)
{
	int a_y = i % 8;  //finds file value
	int a_x = (i - a_y) / 8; //finds row value

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