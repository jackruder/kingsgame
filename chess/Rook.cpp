#include "Rook.h"



Rook::Rook(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id)
	:directions({ Vec2(-1, 0), Vec2(0, 1), Vec2(1, 0), Vec2(0, -1) }), Piece(c, n, brd, i, id)
{
}


Rook::~Rook()
{
}

std::vector<Vec2> Rook::availablemoves()
{
	return ray(directions);
}