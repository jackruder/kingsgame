#pragma once
#include "piece.h"
class Rook : public Piece
{
	std::vector<Vec2> directions;
public:
	Rook(std::string c, std::string n, int _id, Vec2 loc);
	~Rook();
	std::vector<Vec2> availablemoves(Board* b);
};

