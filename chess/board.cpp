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

Square& Board::getSquare(int id)// returns square at location id
{
	return squares[id];
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
	squares.reserve(64); //allocates memory for vector
	for (int r = 0; r < 8; r++)
	{
		for (int f = 0; f < 8; f++)
		{
			string c;
			string n{ files[f], rows[r] };  //algebraic notation name
			if (f + r % 2 == 0)  //if the sum of indicies is even the square is black, otherwise it is white
				c = "black";
			else
				c = "white";
			vector<int> p = { f,r }; //initializes location vector
			squares.emplace_back(n, c, p);
		}
	}
}

void Board::move(shared_ptr<Piece> p, vector<int>& sq)
{
	vector<int> current = p->getPos();
	Square& newSquare = getSquare(sq);  //gets the square at the new location passed to move()

	if (!current.empty())									//checks if the piece is on a square
	{
		Square& currentSquare = getSquare(current);	//gets the square the piece is on
		if (newSquare.getPiece() == nullptr)						//checks if the new square has a piece
		{
			newSquare.setPiece(p);	//if no piece, we just set the piece of the new square to the current piece
			currentSquare.setPiece(nullptr);				//then set the piece of the old square to none
		}
		else												//if there is a piece
		{
			vector<int> empty;								//initialize an empty location
			newSquare.getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
			newSquare.setPiece(p);	//sets the piece of the new square to the current piece
			currentSquare.setPiece(nullptr);				//sets the piece of the old square to none
		}
	}
	else                                                 //if the piece is not on a square
	{
		if (newSquare.getPiece() == nullptr)  //checks if the new square has a piece
		{
			newSquare.setPiece(p); // if no, sets the piece of the new square to the current piece
		}
		else												//if yes,
		{
			vector<int> empty;							    //initialize an empty location
			newSquare.getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
			newSquare.setPiece(p);  //sets the piece of the new square to the current piece

		}
		p->setPos(sq); //sets the locaiton of the current piece to the new location
	}
}

///void Board::genPieces()
