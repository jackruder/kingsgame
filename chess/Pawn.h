#pragma once
#include "piece.h"
class Pawn : public Piece
{
public:
	Pawn(Color c, std::string n, int _id, Vec2 loc);
	~Pawn();
	superptr<Piece> clone() override;
	std::vector<Vec2> availablemoves(Board* b) override;
	std::vector<Vec2> availablemoves(std::shared_ptr<Board> b) override;
	void move(Board* b, Vec2 sq) override;
	void move(std::shared_ptr<Board> b, Vec2 sq) override;
	void move(std::shared_ptr<Board> b, int sq) override;
	void move(std::shared_ptr<Board> b, Coord coor) override;
	void move(Board* b, int sq) override;
	void move(Board* b, Coord coor) override;

};
