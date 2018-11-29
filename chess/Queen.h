#pragma once
#include "piece.h"
class Queen : public Piece
{
	std::vector<Vec2> directions;
public:
	Queen(Color c, std::string n, int _id, Vec2 loc);
	~Queen();
	superptr<Piece> clone() override;
	std::vector<Vec2> availablemoves(Board* b) override;
	std::vector<Vec2> availablemoves(std::shared_ptr<Board> b) override;
};
