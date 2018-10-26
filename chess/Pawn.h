#pragma once
#include "piece.h"
class Pawn : public Piece
{
public:
	Pawn(std::string c, std::string n, int _id, Vec2 loc);
	~Pawn();
	std::vector<Vec2> availablemoves(Board* b);
#
};

