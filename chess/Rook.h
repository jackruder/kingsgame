#pragma once
#include "piece.h"
class Rook : public Piece
{
	std::vector<Vec2> directions;
public:
	Rook(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id);
	~Rook();
	std::vector<Vec2> availablemoves();
};

