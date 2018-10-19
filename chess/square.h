#pragma once
#include <iostream>
#include "Vec2.h"
#include <vector>
#include <memory>
#include "misc.h"
class Piece;

class Square
{
public:
	Square(std::string n, std::string c, Vec2 pos);
	~Square();
	std::string getName() const;
	std::string getColor() const;
	std::shared_ptr<Piece> getPiece() const;
	Vec2 getPos() const;
	
	void setPiece(std::shared_ptr<Piece> p);

private:
	std::string name;
	std::string color;
	std::shared_ptr<Piece> piece;
	Vec2 pos;
};

