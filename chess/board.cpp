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
#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF
Board::Board()
	:	turn(Turn::none)
{
	//instantiate squares then pieces
	genSquares();
	genPieces();

}



Board Board::operator=(const Board& b)
{
	turn = b.getTurn();
	const std::vector<std::shared_ptr<Piece>>& oldpieces = b.getPieces();
	int s = oldpieces.size();
	pieces.clear();
	pieces.reserve(s);
	for (int i = 0; i < s; i++)
	{
		std::shared_ptr<Piece> oldp = oldpieces[i];
		
		pieces.push_back(newp);
	}
	genSquares(squares);
	updatepieces();


}

Board::~Board()
{ 
}


std::vector<Square> Board::getSquares()
{
	return squares;
}

std::vector<std::shared_ptr<Piece>> Board::getPieces()
{
	return pieces;
}

Square* Board::getSquare(Vec2 loc)// returns square at location
{

	return &(squares[toIndex(loc)]);
}

Square* Board::getSquare(int _id)// returns square at location id
{
	return &(squares[_id]);
}

std::shared_ptr<Piece> Board::getPiece(Pname name) // returns pointer to piece by enum name
{
	return pieces[static_cast<int>(name)];
} 
std::shared_ptr<Piece> Board::getPiece(int _id)
{
	return pieces[_id];
}
std::shared_ptr<Piece> Board::getPiece(Vec2 loc)
{
	return getSquare(loc)->getPiece();
}


Turn Board::getTurn()
{
	return turn;
}

void Board::genSquares()
{
	std::string rows = "12345678";
	std::string files = "abcdefgh";
	squares.clear();
	squares.reserve(64); //allocates memory for std::vector
	for (int r = 0; r < 8; r++)
	{
		for (int f = 0; f < 8; f++)
		{
			std::string c;
			std::string n{ files[f], rows[r] };  //algebraic notation name
			if ((f + r) % 2 == 0)  //if the sum of indicies is even the square is black, otherwise it is white
				c = "black";
			else
				c = "white";
			Vec2 p = Vec2(f,r); //initializes location 
		
			squares.emplace_back(n, c, p);
		}
	}
}

void Board::move(std::shared_ptr<Piece> p, Vec2 sq)
{
	Vec2 current = p->getPos();
	Vec2 empty(-1, -1);					//initialize an empty location
	if (sq == empty)
	{
		Square* newSquare = getSquare(sq);  //gets the square at the new location passed to move()
		if (!(current == empty))									//checks if the piece is on a square
		{
			Square* currentSquare = getSquare(current);	//gets the square the piece is on
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

		}
	}
	
	p->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Board::genPieces()
{	
	pieces.clear();
	pieces.reserve(32);
	std::vector<std::string> colors = {"white", "black" };
	int _id = 0;
	for (std::string c : colors)
	{
		char _c = c[0];
		for (int i = 0; i < 2; i++)
		{
			std::string _name(_c + std::string("rook") + std::to_string(i + 1));
			std::shared_ptr<Piece> newp = std::make_shared<Rook>(c, _name, _id, Vec2(-1, -1));
			pieces.push_back(newp);
			_id++;
		}
		for (int i = 0; i < 2; i++)
		{
			std::string _name(_c + std::string("bishop") + std::to_string(i + 1));
			std::shared_ptr<Piece> newp = std::make_shared<Bishop>(c, _name, _id, Vec2(-1, -1));
			pieces.push_back(newp);
			_id++;
		}
		for (int i = 0; i < 2; i++)
		{
			std::string _name(_c + std::string("knight") + std::to_string(i + 1));
			std::shared_ptr<Piece> newp = std::make_shared<Knight>(c, _name, _id, Vec2(-1, -1));
			pieces.push_back(newp);
			_id++;
		}
		{ //scopes to keep same var names
			std::string _name(_c + std::string("king1"));
			std::shared_ptr<Piece> newp = std::make_shared<King>(c, _name, _id, Vec2(-1, -1));
			pieces.push_back(newp);
			_id++;
		}
		{ 
			std::string _name(_c + std::string("queen1"));
			std::shared_ptr<Piece> newp = std::make_shared<Queen>(c, _name, _id, Vec2(-1, -1));
			pieces.push_back(newp);
			_id++;
		}
		for (int i = 0; i < 8; i++)
		{
			std::string _name(_c + std::string("pawn") + std::to_string(i + 1));
			std::shared_ptr<Piece> newp = std::make_shared<Pawn>(c, _name, _id, Vec2(-1, -1));
			pieces.push_back(newp);
			_id++;
		}
	}
}

void Board::setTurn(Turn t)
{
	turn = t;
}

void Board::setPosition(std::vector<Coord> position, Turn t)
{
	genSquares();
	for (int i = 0; i < int(pieces.size()); i++)
	{
		pieces[i]->move(this, toCoord(position[i]));
		turn = t;
	}
}
void Board::starting() //returns board and pieces to starting position
{
	genSquares();
	genPieces();
	setPosition(startpos, Turn::white);
}

void Board::printBoard()
{
	std::cout << "   A     B     C     D     E     F     G     H\n\n";

	for (int iLine = 7; iLine >= 0; iLine--)
	{
		if (iLine % 2 == 0)
		{
			// Line starting with BLACK
			printLine(iLine, BLACK_SQUARE, WHITE_SQUARE);
		}

		else
		{
			// Line starting with WHITE
			printLine(iLine, WHITE_SQUARE, BLACK_SQUARE);
		}
	}
}

void Board::printLine(int iLine, int iColor1, int iColor2)
{
	// Define the CELL variable here. 
	// It represents how many horizontal characters will form one square
	// The number of vertical characters will be CELL/2
	// You can change it to alter the size of the board 
	// (an odd number will make the squares look rectangular)
	int SIZE = 1; // 1 through 4
	int cell = 2 + 4 * SIZE;
	int mCol = cell / 2;
	int mLine = (mCol - 1) / 2;
	// Since the width of the characters BLACK and WHITE is half of the height, 
	// we need to use two characters in a row.
	// So if we have CELL characters, we must have CELL/2 sublines
	for (int subLine = 0; subLine < cell / 2; subLine++)
	{
		// A sub-line is consisted of 8 cells, but we can group it
		// in 4 iPairs of black&white
		for (int iPair = 0; iPair < 4; iPair++)
		{
			// First cell of the pair
			for (int subColumn = 0; subColumn < cell; subColumn++)
			{
				// The piece should be in the "middle" of the cell
				// For 3 sub-lines, in sub-line 1
				// For 6 sub-columns, sub-column 3
				if (subLine == mLine && subColumn == mCol)
				{
					std::cout << char(getPiece(Vec2(iPair * 2, iLine)) != nullptr ?
						getPiece(Vec2(iPair * 2, iLine))->getSymb() : iColor1);
				}
				else
				{
					std::cout << char(iColor1);
				}
			}

			// Second cell of the pair
			for (int subColumn = 0; subColumn < cell; subColumn++)
			{
				// The piece should be in the "middle" of the cell
				// For 3 sub-lines, in sub-line 1
				// For 6 sub-columns, sub-column 3
				if (subLine == mLine && subColumn == mCol)
				{
					std::cout << char(getPiece(Vec2(iPair * 2 + 1, iLine)) != nullptr ?
						getPiece(Vec2(iPair * 2 + 1, iLine))->getSymb() : iColor2);
				}
				else
				{
					std::cout << char(iColor2);
				}
				if (iPair == 3 && subColumn == (cell - 1) && subLine == mLine)
					std::cout << "   " << std::to_string(iLine + 1);
			}

		}
		std::cout << std::endl;
	}
}

