#pragma once
#include "piece.h"
class Rook : public Piece
{
	std::vector<Vec2> directions;
public:
	
	Rook(Color c, std::string n, int _id, Vec2 loc);
	~Rook();

	virtual std::shared_ptr<Piece> clone();

	std::vector<Vec2> availablemoves(Board* b);
	std::vector<Vec2> availablemoves(std::shared_ptr<Board> b);
};

