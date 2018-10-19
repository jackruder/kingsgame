#pragma once
#include "piece.h"
class Knight : public Piece
{
	std::vector<Vec2> directions;
public:
	Knight(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id);
	~Knight();
	std::vector<Vec2> availablemoves();
};

