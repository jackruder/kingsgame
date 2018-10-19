#include "Knight.h"



Knight::Knight(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id)
	:directions({ Vec2(-2, -1), Vec2(-2, 1), Vec2(1, -2), Vec2(1, 2), Vec2(-1, -2), Vec2(-1, 2), Vec2(2, 1), Vec2(2, -1) }), Piece(c, n, brd, i, id)
{
}

Knight::~Knight()
{
}

std::vector<Vec2> Knight::availablemoves()
{
	std::vector<Vec2> moves;
	for (int d = 1; d < directions.size(); d++)
	{
		Vec2 newpos(directions[d] + pos);
		if (vacant(newpos))
		{
			moves.push_back(newpos);
		}
	}
	return moves;
}

