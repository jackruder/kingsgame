#include "Bishop.h"



Bishop::Bishop(std::string c, std::string n, int _id, Vec2 loc)
	:directions({ Vec2(-1, -1), Vec2(-1, 1), Vec2(1, -1), Vec2(1, 1) }), Piece(c,n, _id, loc)
{
	symb = c == "white" ? 'B' : 'b';
}

Bishop::~Bishop()
{
}

std::vector<Vec2> Bishop::availablemoves(Board* b)
{
	return ray(b, directions);
}

std::vector<Vec2> Bishop::availablemoves(std::shared_ptr<Board> b)
{
	return ray(b, directions);
}
