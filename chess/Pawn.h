#pragma once
#include "piece.h"
class Pawn : public Piece
{
public:
	Pawn(Color c, std::string n, int _id, Vec2 loc);
	~Pawn();
	std::shared_ptr<Piece> clone();
	std::vector<Vec2> availablemoves(Board* b);
	std::vector<Vec2> availablemoves(std::shared_ptr<Board> b);
	void move(Board* b, Vec2 sq);
	void move(std::shared_ptr<Board> b, Vec2 sq);
	void move(std::shared_ptr<Board> b, int sq);
	void move(std::shared_ptr<Board> b, Coord coor);
	void move(Board* b, int sq);
	void move(Board* b, Coord coor);

};
