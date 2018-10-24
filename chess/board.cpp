#include "board.h"
#include <typeinfo>
#include <string>
#include "piece.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
Board::Board()
	:	turn(Turn::none)
{
	//instantiate squares then pieces
	genSquares(squares);
	genPieces(pieces);
	starting();


}



/*Board Board::operator=(const Board& b)
{
	turn = b.getTurn();
	const std::vector<std::shared_ptr<Piece>>& oldpieces = b.getPieces();
	int s = oldpieces.size();
	pieces.clear();
	pieces.reserve(s);
	for (int i = 0; i < s; i++)
	{
		std::shared_ptr<Piece> oldp = oldpieces[i];
		std::shared_ptr<Piece> newp = std::make_shared<WTF>(*oldp);
		pieces.push_back(newp);
	}
	genSquares(squares);
	updatepieces();


}*/

Board::~Board()
{ 
}


std::vector<std::shared_ptr<Square>> Board::getSquares() const
{
	return squares;
}

std::vector<std::shared_ptr<Piece>> Board::getPieces() const
{
	return pieces;
}

std::shared_ptr<Square> Board::getSquare(Vec2 pos) const // returns square at location
{
	return squares[toIndex(pos)];
}

std::shared_ptr<Square> Board::getSquare(int id) const // returns square at location id
{
	return squares[id];
}

std::shared_ptr<Piece> Board::getPiece(Pname name) const // returns pointer to piece by enum name
{
	return pieces[static_cast<int>(name)];
} 
std::shared_ptr<Piece> Board::getPiece(int id) const
{
	return pieces[id];
}
std::shared_ptr<Piece> Board::getPiece(Vec2 loc) const
{
	std::shared_ptr<Square> s = getSquare(loc);
	return s->getPiece();
}


Turn Board::getTurn() const
{
	return turn;
}

void Board::genSquares(std::vector<std::shared_ptr<Square>>& storage)
{
	std::string rows = "12345678";
	std::string files = "abcdefgh";
	storage.reserve(64); //allocates memory for std::vector
	for (int r = 0; r < 8; r++)
	{
		for (int f = 0; f < 8; f++)
		{
			std::string c;
			std::string n{ files[f], rows[r] };  //algebraic notation name
			if (f + r % 2 == 0)  //if the sum of indicies is even the square is black, otherwise it is white
				c = "black";
			else
				c = "white";
			Vec2 p = Vec2(f,r); //initializes location 
			std::shared_ptr<Square> newsquare = std::make_shared<Square>(n, c, p);
			storage.push_back(newsquare);
		}
	}
}

void Board::move(std::shared_ptr<Piece> p, Vec2 sq)
{
	Vec2 current = p->getPos();
	std::shared_ptr<Square> newSquare = getSquare(sq);  //gets the square at the new location passed to move()
	Vec2 empty(-1, -1);					//initialize an empty location
	if (!(current == empty))									//checks if the piece is on a square
	{
		std::shared_ptr<Square> currentSquare = getSquare(current);	//gets the square the piece is on
		if (newSquare->getPiece() == nullptr)						//checks if the new square has a piece
		{
			newSquare->setPiece(p);	//if no piece, we just set the piece of the new square to the current piece
			currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
		}
		else												//if there is a piece
		{										
			newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
			newSquare->setPiece(p);	//sets the piece of the new square to the current piece
			currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
		}
	}
	else                                                 //if the piece is not on a square
	{
		if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
		{
			newSquare->setPiece(p); // if no, sets the piece of the new square to the current piece
		}
		else												//if yes,
		{
			newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
			newSquare->setPiece(p);  //sets the piece of the new square to the current piece

		}
		p->setPos(sq); //sets the locaiton of the current piece to the new location
	}
}

void Board::updatepieces()
{
	for (std::shared_ptr<Piece> _p : pieces)
	{
		Vec2 pos = _p->getPos();
		if (pos != Vec2(-1, -1))
			_p->move(pos);
		else
			std::cout << _p->getName() << " does not have a location, no update required" << std::endl;
	}
}

void Board::genPieces(std::vector<std::shared_ptr<Piece>>& storage)
{	
	storage.clear();
	storage.reserve(32);
	std::string colors[2] = { "white", "black" };
	int _id = 0;
	for (std::string c : colors)
	{
		char _c = c[0];
		for (int i = 0; i < 2; i++)
		{
			std::string name = _c + "rook" + static_cast<char>(i + 1);
			std::shared_ptr<Piece> newp = std::make_shared<Rook>(c, name, weak_from_this(), _id, Vec2(-1, -1));
			storage.push_back(newp);
			_id++;
		}
		for (int i = 0; i < 2; i++)
		{
			std::string name = _c + "bishop" + static_cast<char>(i + 1);
			std::shared_ptr<Piece> newp = std::make_shared<Bishop>(c, name, weak_from_this(), _id, Vec2(-1, -1));
			storage.push_back(newp);
			_id++;
		}
		for (int i = 0; i < 2; i++)
		{
			std::string name = _c + "knight" + static_cast<char>(i + 1);
			std::shared_ptr<Piece> newp = std::make_shared<Knight>(c, name, weak_from_this(), _id, Vec2(-1, -1));
			storage.push_back(newp);
			_id++;
		}
		{ //scopes to keep same var names
			std::string name = _c + "king1";
			std::shared_ptr<Piece> newp = std::make_shared<King>(c, name, weak_from_this(), _id, Vec2(-1, -1));
			storage.push_back(newp);
			_id++;
		}
		{ 
			std::string name = _c + "queen1";
			std::shared_ptr<Piece> newp = std::make_shared<Queen>(c, name, weak_from_this(), _id, Vec2(-1, -1));
			storage.push_back(newp);
			_id++;
		}
		for (int i = 0; i < 8; i++)
		{
			std::string name = _c + "pawn" + static_cast<char>(i + 1);
			std::shared_ptr<Piece> newp = std::make_shared<Pawn>(c, name, weak_from_this(), _id, Vec2(-1, -1));
			storage.push_back(newp);
			_id++;
		}
	}
}
void Board::setPosition(std::vector<int> position, Turn t)
{
	for (int i = 0; i < static_cast<int>(pieces.size()); i++)
	{
		pieces[i]->setPos(position[i]);	
	}
	updatepieces();
	turn = t;
}
void Board::starting() //returns board and pieces to starting position
{
	setPosition(startpos, Turn::white);
}
