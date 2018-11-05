#include "Queen.h"



Queen::Queen(std::string c, std::string n, int _id, Vec2 loc)
	:directions({ Vec2(-1, -1), Vec2(-1, 1), Vec2(1, -1), Vec2(1, 1), Vec2(-1, 0), Vec2(0, 1), Vec2(1, 0), Vec2(0, -1) }), Piece(c, n, _id, loc)
{
	symb = c == "white" ? 'Q' : 'q';
}


Queen::~Queen()
{
}

std::vector<Vec2> Queen::availablemoves(Board* b)
{
	return ray(b, directions);
}

std::vector<Vec2> Queen::availablemoves(std::shared_ptr<Board> b)
{
	return ray(b, directions);
}