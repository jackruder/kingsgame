#pragma once
#include <iostream> 
#include <vector>
#include <memory>
#include "misc.h"
#include "Vec2.h"
#include "board.h"
#include <string>
class Board;


class Piece
{
public:

	Piece(Color c, std::string n, int i, Vec2 loc); 

	~Piece();
	int getID();
	char getSymb() const;
	Color getColor() const;
	std::string getName() const;

	Vec2 getPos();
	void setPos(Vec2 p);
	void setPos(int p);
	void move(Board* b, Vec2 sq);
	void move(std::shared_ptr<Board> b, Vec2 sq);
	void move(std::shared_ptr<Board> b, int sq);
	void move(std::shared_ptr<Board> b, Coord coor);
	void move(Board * b, int sq);
	void move(Board * b, Coord coor);
	friend std::ostream &operator<<(std::ostream &output, const Piece& p);
	virtual std::vector<Vec2> availablemoves(Board *b) = 0;
	virtual std::vector<Vec2> availablemoves(std::shared_ptr<Board> b) = 0;
protected:

	int id;
	Color color;
	const std::string piecename;
	Vec2 pos; // Pieces should be initialized with no location, which will be a nullptr
	char symb;
	bool vacant(Board* b, Vec2 npos);  //checks if a square is allowed, regardless of check, turn, etc,.
	bool vacant(std::shared_ptr<Board> b, Vec2 npos);
	std::vector<Vec2> ray(Board *b, const std::vector<Vec2>& directions);
	std::vector<Vec2> ray(std::shared_ptr<Board> b, const std::vector<Vec2>& directions);

};
