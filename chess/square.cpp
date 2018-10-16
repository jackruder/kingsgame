#include "square.h"



Square::Square(string n, string c, vector<int> p)
	:name(n), color(c), pos(p)
{
}


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