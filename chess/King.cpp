#include "King.h"



King::King(Color c, std::string n, int _id, Vec2 loc)
	:directions({ Vec2(-1, -1), Vec2(-1, 1), Vec2(1, -1), Vec2(1, 1), Vec2(-1, 0), Vec2(0, 1), Vec2(1, 0), Vec2(0, -1) }), Piece(c, n, _id, loc)
{
	symb = c == Color::white ? 'K' : 'k';
}


King::~King()
{
}

std::vector<Vec2> King::availablemoves(Board* b)
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

std::vector<Vec2> King::availablemoves(std::shared_ptr<Board> b)
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

superptr<Piece> King::clone()
{
	return superptr<Piece>(std::make_shared<std::unique_ptr<Piece>>(std::make_unique<King>(*this)));
}
