#pragma once
#include "piece.h"
class Bishop : public Piece
{
	std::vector<Vec2> directions;
public:
	Bishop(std::string c, std::string n, int _id, Vec2 loc);
	~Bishop();
	std::vector<Vec2> availablemoves(Board* b);

};

