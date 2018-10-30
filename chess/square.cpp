#include "square.h"
#include "piece.h"

//constructor
Square::Square(std::string n, std::string c, Vec2 p)
	:name(n), color(c), pos(p), piece(nullptr)
{
}

//destructor  -- needs to be written
Square::~Square()
{
}

//getter functions

std::string Square::getName()
{
	return name;
}


std::string Square::getColor()
{
	return color;
}

Vec2 Square::getPos()
{
	return pos;
}

std::shared_ptr<Piece> Square::getPiece() const
{
	return piece;
}

//setter functions
void Square::setPiece(std::shared_ptr<Piece> p)
{
	piece = p;
}

std::ostream &operator<<(std::ostream &output, const Square& s)
{
	std::string p;
	if (s.getPiece() == nullptr)
		p = "none";
	else
		p = s.getPiece()->getName();
	output << "Square " << s.name << "- " << p;
	return output;
}