#pragma once
#include "piece.h"
class Pawn : public Piece
{
public:
	Pawn(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id);
	~Pawn();
	std::vector<Vec2> availablemoves();
#
};

