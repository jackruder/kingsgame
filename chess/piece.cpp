#include "piece.h" 
using namespace std;


//constructor
Piece::Piece(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id)
	: color(c), name(n), bptr(brd), identifier(i), pos()
{

}



// Getter functions
std::string Piece::getName() const 
{
	return name;
}

std::string Piece::getColor() const
{
	return color;
}

int Piece::getId() const
{
	return id;
}

int Piece::getSymb() const
{
	return symb;
}

std::weak_ptr<Board> Piece::getBoardPtr() const
{
	return bptr;
}

Vec2 Piece::getPos()
{
	return pos;
}

void Piece::setPos(Vec2 p)
{
	pos = p;
}

// Member Functions

bool Piece::vacant(const Vec2& npos)  //checks if a square is allowed, regardless of check, turn, etc,.
{
	if (onBoard(npos))
	{
		std::shared_ptr<Board> b = bptr.lock(); //access board
		std::shared_ptr<Piece> p = b->getPiece(npos);  //gets the ptr to piece at new position; nullptr if no piece
		if (p == nullptr) // no piece, so square is vacant
			return true;
		else if (p->getColor() == color) //if new square has a piece of the same color, square is not vacant
			return false;
		else
			return true; //square then only can have a piece of a differrent color
	}
	else
		return false; //cant move off the board

}

/*std::vector<Vec2> Piece::ray(std::vector<Vec2> directions)
{

}*/