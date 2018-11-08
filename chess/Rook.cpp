#include "Rook.h"



Rook::Rook(Color c, std::string n, int _id, Vec2 loc)
	:directions({ Vec2(-1, 0), Vec2(0, 1), Vec2(1, 0), Vec2(0, -1) }), Piece(c, n, _id, loc)
{
	symb = c == Color::white ? 'R' : 'r';
}


Rook::~Rook()
{
}

std::vector<Vec2> Rook::availablemoves(Board* b)
{
	return ray(b, directions);
}

std::vector<Vec2> Rook::availablemoves(std::shared_ptr<Board> b)
{
	return ray(b, directions);
}