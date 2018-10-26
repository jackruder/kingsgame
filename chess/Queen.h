#pragma once
#include "piece.h"
class Queen : public Piece
{
	std::vector<Vec2> directions;
public:
	Queen(std::string c, std::string n, int _id, Vec2 loc);
	~Queen();
	std::vector<Vec2> availablemoves(Board* b);
};
