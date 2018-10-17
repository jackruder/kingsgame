#include "misc.h"

using namespace std;
int toIndex(vector<int> a)
{
	int b = (8 * a[1] + a[0]);
	return b;
}


vector<int> toCoord(int i)
{
	int a_y = i % 8;
	int a_x = (i - a_y) / 8;

	vector<int> a = { a_x, a_y };

	return a;
}

bool onBoard(int f, int r)
{
	if (f >= 0 && f < 8 && r >= 0 && r < 8)
		return true;
	else
		return false;
}

bool onBoard(vector<int> pos)
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