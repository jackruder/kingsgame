#include "piece.h" 
using namespace std;


//constructor
Piece::Piece(string c, string n, shared_ptr<Board> brd, Pname i, int id)
	: color(c), name(n), bptr(brd), identifier(i), pos({})
{

}



// Getter functions
string Piece::getName() const 
{
	return name;
}

string Piece::getColor() const
{
	return color;
}

int Piece::getId() const
{
	return id;
}

char Piece::getSymb() const
{
	return symb;
}

weak_ptr<Board> Piece::getBoardPtr() const
{
	return bptr;
}

vector<int> Piece::getPos()
{
	return pos;
}

void Piece::setPos(vector<int> p)
{
	pos = p;
}

// Member Functions

bool Piece::vacant(const vector<int>& npos)  //checks if a square is allowed, regardless of check, turn, etc,.
{
	if (onBoard(npos))
	{
		shared_ptr<Board> b = bptr.lock(); //access board
		shared_ptr<Piece> p = b->getPiece(npos);  //gets the ptr to piece at new position; nullptr if no piece
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

vector<vector<int>> Piece::ray(vector<vector<int>> directions)
{

}