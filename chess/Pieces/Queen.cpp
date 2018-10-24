#include "Queen.h"



Queen::Queen(std::string c, std::string n, std::weak_ptr<Board> brd, int _id, Vec2 loc)
	:directions({ Vec2(-1, -1), Vec2(-1, 1), Vec2(1, -1), Vec2(1, 1), Vec2(-1, 0), Vec2(0, 1), Vec2(1, 0), Vec2(0, -1) }), Piece(c, n, brd, _id, loc)
{
}


Queen::~Queen()
{
}

std::vector<Vec2> Queen::availablemoves()
{
	return ray(directions);
}