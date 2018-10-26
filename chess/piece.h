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

	Piece(std::string c, std::string n, int i, Vec2 loc); 

	~Piece();
	int getID();
	int getSymb() const;
	std::string getColor() const;
	std::string getName() const;

	Vec2 getPos();
	void setPos(Vec2 p);
	void setPos(int p);
	void move(Board* b, Vec2 sq);
	friend std::ostream &operator<<(std::ostream &output, const Piece& p);
	virtual std::vector<Vec2> availablemoves(Board *b) = 0;
protected:

	int id;
	std::string color;
	std::string name;
	Vec2 pos; // Pieces should be initialized with no location, which will be a nullptr
	int symb;
	bool vacant(Board* b, const Vec2& npos);  //checks if a square is allowed, regardless of check, turn, etc,.
	std::vector<Vec2> ray(Board *b, const std::vector<Vec2>& directions);

};
