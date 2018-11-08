#pragma once
#include <iosfwd>
#include "Vec2.h"
#include <vector>
#include <memory>
#include "misc.h"
#include <string>
class Piece;
class Vec2;
class Square
{
public:
	Square(std::string n, std::string c, Vec2 pos);
	~Square();
	std::string getName();
	std::string getColor();
	std::shared_ptr<Piece> getPiece() const;
	Vec2 getPos();
	void setPiece(std::shared_ptr<Piece> p);
	friend std::ostream &operator<<(std::ostream &output, const Square& s);

private:
	std::string name;
	std::string color;
	std::shared_ptr<Piece> piece;
	Vec2 pos;
};

