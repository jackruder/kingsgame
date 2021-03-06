#include "Knight.h"



Knight::Knight(Color c, std::string n, int _id, Vec2 loc)
	:directions({ Vec2(-2, -1), Vec2(-2, 1), Vec2(1, -2), Vec2(1, 2), Vec2(-1, -2), Vec2(-1, 2), Vec2(2, 1), Vec2(2, -1) }), Piece(c, n, _id, loc)
{
	symb = c == Color::white ? 'N' : 'n';
}

Knight::~Knight()
{
}

std::vector<Vec2> Knight::availablemoves(Board* b)
{
	std::vector<Vec2> moves;
	for (int d = 0; d < 8; d++)
	{
		Vec2 newpos(directions[d] + pos);
		if (vacant(b, newpos))
		{
			moves.push_back(newpos);
		}
	}
	return moves;
}

std::vector<Vec2> Knight::availablemoves(std::shared_ptr<Board> b)
{
	std::vector<Vec2> moves;
	for (int d = 0; d < 8; d++)
	{
		Vec2 newpos(directions[d] + pos);
		if (vacant(b, newpos))
		{
			moves.push_back(newpos);
		}
	}
	return moves;
}

superptr<Piece> Knight::clone()
{
	return superptr<Piece>(std::make_shared<std::unique_ptr<Piece>>(std::make_unique<Knight>(*this)));
}
