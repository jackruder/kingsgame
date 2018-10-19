#pragma once
#include "piece.h"
class Bishop : public Piece
{
	std::vector<Vec2> directions;
public:
	Bishop(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id);
	~Bishop();
	std::vector<Vec2> availablemoves();

};

