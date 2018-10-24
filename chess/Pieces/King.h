#pragma once
#include "piece.h"
class King : public Piece
{
	std::vector<Vec2> directions;
public:
	King(std::string c, std::string n, std::weak_ptr<Board> brd, int _id, Vec2 loc);
	~King();
	std::vector<Vec2> availablemoves();
};

