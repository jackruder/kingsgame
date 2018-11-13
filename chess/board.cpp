#include "board.h"
#include "square.h"
#include <iostream>
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
	:	turn(Color::white)
{
	//instantiate squares then pieces
	genSquares();
	genPieces();
}

Board::Board(const Board& b)
	: turn(b.getTurn()), moved2(b.getMoved2()), squares(b.getSquares())
{
	genSquares();
	std::vector<std::shared_ptr<Piece>> oldPieces = b.getPieces();
	pieces.reserve(32);
	for (std::shared_ptr<Piece> oldp : oldPieces)
	{
		std::shared_ptr<Piece> p = oldp->clone();
		squares[toIndex(p->getPos())].setPiece(p);
		pieces.push_back(p);
	}
	
	

}


Board& Board::operator=(const Board& b)
{
	std::vector<std::shared_ptr<Piece>> oldPieces = b.getPieces();
	pieces.clear();
	pieces.reserve(32);
	genSquares();
	for (std::shared_ptr<Piece> oldp : oldPieces)
	{
		std::shared_ptr<Piece> p = oldp->clone();
		squares[toIndex(p->getPos())].setPiece(p);
		pieces.push_back(p);
	}
	turn = b.getTurn();
	moved2 = b.getMoved2();
	return *this;
}

Board::~Board()
{ 
}

std::vector<Square> Board::getSquares() const
{
	return squares;
}

std::vector<std::shared_ptr<Piece>> Board::getPieces() const
{
	return pieces;
}

Square* Board::getSquare(Vec2 loc) // returns square at location 
{

	return &(squares[toIndex(loc)]);
}

Square* Board::getSquare(int _id) // returns square at location id
{
	return &(squares[_id]);
}

std::shared_ptr<Piece> Board::getPiece(Pname name)// returns pointer to piece by enum name
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

std::string Board::getMoved2() const {
	return moved2;
}

void Board::setMoved2(std::string p) {
	moved2 = p;
}

Color Board::getTurn() const
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



void Board::genPieces()
{	
	pieces.clear();
	pieces.reserve(32);
	char colors[2] = {'w', 'b' };
	int _id = 0;
	for (int k = 0; k < 2; k++)
	{
		Color c = static_cast<Color>(k);
		char _c = colors[k];
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

void Board::setTurn(Color t)
{
	turn = t;
}

std::vector<Coord> Board::getPosition() const
{
	std::vector<Coord> position;
	position.reserve(32);
	for (std::shared_ptr<Piece> p : pieces)
	{
		position.push_back(toCoord(p->getPos()));
	}
	return position;
}

void Board::setPosition(std::vector<Coord> position, Color t) //this function wont work after promotion
{
	turn = t;
	genSquares();
	for (int i = 0; i < int(pieces.size()); i++) 
	{
		pieces[i]->move(this, toVec(position[i]));	
	}
}
void Board::starting() //returns board and pieces to starting position
{
	genSquares();
	genPieces();
	setPosition(startpos, Color::white);
}

void Board::printBoard()
{
	int SIZE = 2; // 1 through 4
	int cell = 2 + 4 * SIZE;
	std::string header;
	std::string fnames = "ABCDEFGH";
	for (int i = 0; i < 7; i++)
	{		
		for (int s = 0; s < (cell / 2); s++)
		{
			header += ' ';
		}
		header += fnames[i];
		for (int s = 0; s < (cell / 2) - 1; s++)
		{
			header += ' ';
		}
	}
	for (int s = 0; s < (cell / 2); s++)
	{
		header += ' ';
	}
	header += "H\n\n";
	std::cout << header;

	for (int iLine = 7; iLine >= 0; iLine--)
	{
		if (iLine % 2 == 0)
		{
			// Line starting with BLACK
			printLine(iLine, BLACK_SQUARE, WHITE_SQUARE, cell);
		}

		else
		{
			// Line starting with WHITE
			printLine(iLine, WHITE_SQUARE, BLACK_SQUARE, cell);
		}
	}
}

void Board::printLine(int iLine, int iColor1, int iColor2, int cell)
{
	// Define the CELL variable here. 
	// It represents how many horizontal characters will form one square
	// The number of vertical characters will be CELL/2
	// You can change it to alter the size of the board 
	// (an odd number will make the squares look rectangular)
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

void Board::updateSquares()
{
	for (std::shared_ptr<Piece> p : pieces)
	{
		p->move(this, p->getPos());
	}
}

bool Board::inCheck(Color c)
{
	int first;
	int king;
	if (c == Color::white)
	{
		first = 16;
		king = 6;
	}
	else
	{
		first = 0;
		king = 22;
	}
	Vec2 kpos = pieces[king]->getPos();
	for (int i = first; i < (first + 16); i++)
	{
		std::shared_ptr<Piece> p = pieces[i];
		std::vector<Vec2> moves = p->availablemoves(this);
		for (Vec2 m : moves)
		{
			if (m == kpos)
				return true;
		}
	}
	return false;
}

void Board::nextTurn()
{
	if (turn == Color::white)
	{
		if (moved2[0] == 'b')
			moved2 = "none";
		turn = Color::black;
	}
	else
	{
		if (moved2[0] == 'w')
			moved2 = "none";
		turn = Color::white;
	}
	

}


