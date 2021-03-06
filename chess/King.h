#pragma once
#include "piece.h"
class King : public Piece
{
	std::vector<Vec2> directions;
public:
	King(Color c, std::string n, int _id, Vec2 loc);
	~King();
	std::vector<Vec2> availablemoves(Board* b) override;
	std::vector<Vec2> availablemoves(std::shared_ptr<Board> b) override;
	superptr<Piece> clone() override;
};

