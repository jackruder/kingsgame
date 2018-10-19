#pragma once
#include "piece.h"
class King : public Piece
{
	std::vector<Vec2> directions;
public:
	King(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id);
	~King();
	std::vector<Vec2> availablemoves();
};

