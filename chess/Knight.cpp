#include "Knight.h"



Knight::Knight(std::string c, std::string n, std::weak_ptr<Board> brd, int _id, Vec2 loc)
	:directions({ Vec2(-2, -1), Vec2(-2, 1), Vec2(1, -2), Vec2(1, 2), Vec2(-1, -2), Vec2(-1, 2), Vec2(2, 1), Vec2(2, -1) }), Piece(c, n, brd, _id, loc)
{
}

Knight::~Knight()
{
}

std::vector<Vec2> Knight::availablemoves()
{
	std::vector<Vec2> moves;
	for (int d = 1; d < static_cast<int>(directions.size()); d++)
	{
		Vec2 newpos(directions[d] + pos);
		if (vacant(newpos))
		{
			moves.push_back(newpos);
		}
	}
	return moves;
}

