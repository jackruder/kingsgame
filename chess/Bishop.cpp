#include "Bishop.h"



Bishop::Bishop(Color c, std::string n, int _id, Vec2 loc)
	:directions({ Vec2(-1, -1), Vec2(-1, 1), Vec2(1, -1), Vec2(1, 1) }), Piece(c,n, _id, loc)
{
	symb = c == Color::white ? 'B' : 'b';
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

superptr<Piece> Bishop::clone()
{
	return superptr<Piece>(std::make_shared<std::unique_ptr<Piece>>(std::make_unique<Bishop>(*this)));
}
