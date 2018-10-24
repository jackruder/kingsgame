#include "Pawn.h"


Pawn::Pawn(std::string c, std::string n, std::weak_ptr<Board> brd, int _id, Vec2 loc)
	:Piece(c, n, brd, _id, loc)
{
}

Pawn::~Pawn()
{
}

std::vector<Vec2> Pawn::availablemoves()
{
	std::vector<Vec2> moves;
	int t;
	Vec2 d;
	if (color == "white")
	{
		t = 1;
		Vec2 d(0, 1);
	}
	else
	{

		t = 6;
		Vec2 d(0, -1);
	}
	if (pos[1] == t)
	{
		Vec2 forward2(pos[0], pos[1] + 2 * d[1]);
		if (vacant(forward2)) 
		{
			moves.push_back(forward2);
		}			
	}
	int newposr = pos[1] + d[1];
	Vec2 forward1(pos[0], newposr);
	Vec2 capleft(pos[0] - 1, newposr);
	Vec2 capright(pos[0] + 1, newposr);
	Vec2 caps[2] = { capleft, capright };
	if (vacant(forward1))
	{
		moves.push_back(forward1);
	}
	for (Vec2 v : caps)
		if (vacant(v) && !(bptr.lock()->getPiece(v) == nullptr))
		{
			moves.push_back(v);
		}
	return moves;
}
