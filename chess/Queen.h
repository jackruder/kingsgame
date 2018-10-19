#pragma once
#include "piece.h"
class Queen : public Piece
{
	std::vector<Vec2> directions;
public:
	Queen(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id);
	~Queen();
	std::vector<Vec2> availablemoves();
};
