#pragma once
#include "piece.h"
class Pawn : public Piece
{
public:
	Pawn(Color c, std::string n, int _id, Vec2 loc);
	~Pawn();
	std::vector<Vec2> availablemoves(Board* b);
	std::vector<Vec2> availablemoves(std::shared_ptr<Board> b);

};
