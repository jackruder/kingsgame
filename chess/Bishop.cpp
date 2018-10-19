#include "Bishop.h"



Bishop::Bishop(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id)
	:directions({ Vec2(-1, -1), Vec2(-1, 1), Vec2(1, -1), Vec2(1, 1) }), Piece(c,n,brd,i,id)
{
}

Bishop::~Bishop()
{
}

std::vector<Vec2> Bishop::availablemoves()
{
	return ray(directions);
}
