#include "board.h"
#include <string>
#include "piece.h"
Board::Board()
	:	turn(Turn::none)
{
	//instantiate squares then pieces
	genSquares();
}

Board::~Board() 
{ 
}

Square& Board::getSquare(vector<int> pos)// returns square at location
{
	return squares[toIndex(pos)];
}

Square& Board::getSquare(int pos)// returns square at location 
{
	return squares[pos];
}

shared_ptr<Piece> Board::getPiece(Pname name) // returns pointer to piece by enum name
{
	return pieces[static_cast<int>(name)];
} 
shared_ptr<Piece> Board::getPiece(int id)
{
	return pieces[id];
}
shared_ptr<Piece> Board::getPiece(vector<int> loc)
{
	Square& s = getSquare(loc);
	return s.getPiece();
}





Turn Board::getTurn() const
{
	return turn;
}

void Board::genSquares()
{
	string rows = "12345678";
	string files = "abcdefgh";
	squares.reserve(64);
	for (int r = 0; r < 8; r++)
	{
		for (int f = 0; f < 8; f++)
		{
			string c;
			string n{ files[f], rows[r] };
			if (f + r == 0)
				c = "black";
			else
				c = "white";
			vector<int> p = { f,r };
			squares.emplace_back(n, c, p);
		}
	}
}

///void Board::genPieces()
