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

std::string Square::getName() const
{
	return name;
}

std::string Square::getColor() const
{
	return color;
}

Vec2 Square::getPos() const
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