#include "King.h"



King::King(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id)
	:directions({ Vec2(-1, -1), Vec2(-1, 1), Vec2(1, -1), Vec2(1, 1), Vec2(-1, 0), Vec2(0, 1), Vec2(1, 0), Vec2(0, -1) }), Piece(c, n, brd, i, id)
{
}

King::~King()
{
}

std::vector<Vec2> King::availablemoves()
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