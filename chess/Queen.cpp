#include "Queen.h"



Queen::Queen(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id)
	:directions({ Vec2(-1, -1), Vec2(-1, 1), Vec2(1, -1), Vec2(1, 1), Vec2(-1, 0), Vec2(0, 1), Vec2(1, 0), Vec2(0, -1) }), Piece(c, n, brd, i, id)
{
}


Queen::~Queen()
{
}

std::vector<Vec2> Queen::availablemoves()
{
	return ray(directions);
}