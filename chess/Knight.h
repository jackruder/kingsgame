#pragma once
#include "piece.h"
class Knight : public Piece
{
	std::vector<Vec2> directions;
public:
	Knight(Color c, std::string n, int _id, Vec2 loc);
	~Knight();
	std::vector<Vec2> availablemoves(Board* b);
	std::vector<Vec2> availablemoves(std::shared_ptr<Board> b);
};

