#include "square.h"


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

std::shared_ptr<Piece> Square::getPiece()
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
	output << s.name;
	return output;
}