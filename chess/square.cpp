#include "square.h"


//constructor
Square::Square(string n, string c, vector<int> p)
	:name(n), color(c), pos(p), piece(nullptr)
{
}

//destructor  -- needs to be written
Square::~Square()
{
}

//getter functions

string Square::getName() const
{
	return name;
}

string Square::getColor() const
{
	return color;
}

vector<int> Square::getPos() const
{
	return pos;
}

shared_ptr<Piece> Square::getPiece() const
{
	return piece;
}

//setter functions
void Square::setPiece(shared_ptr<Piece> p)
{
	piece = p;
}