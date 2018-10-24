#include "piece.h" 
using namespace std;


//constructor
Piece::Piece(std::string c, std::string n, std::weak_ptr<Board> brd, int i, Vec2 loc)
	: color(c), name(n), bptr(brd), id(i), pos(loc)
{

}

Piece::~Piece()
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

int Piece::getID()
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
void Piece::setPos(int p)
{
	pos = toCoord(p);
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



void Piece::move(Vec2 sq){
	Vec2 current = pos;
	std::shared_ptr<Square> newSquare = bptr.lock()->getSquare(sq);  //gets the square at the new location passed to move()
	Vec2 empty(-1, -1);                         //initialize an empty location
	if (!(current == empty))									//checks if the piece is on a square
	{
		std::shared_ptr<Square> currentSquare = bptr.lock()->getSquare(current);	//gets the square the piece is on
		if (newSquare->getPiece() == nullptr)						//checks if the new square has a piece
		{
			newSquare->setPiece(bptr.lock()->getPiece(id));	//if no piece, we just set the piece of the new square to the current piece
			currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
		}
		else												//if there is a piece
		{
			newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
			newSquare->setPiece(bptr.lock()->getPiece(id));	//sets the piece of the new square to the current piece
			currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
		}
	}
	else                                                 //if the piece is not on a square
	{
		if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
		{
			newSquare->setPiece(bptr.lock()->getPiece(id)); // if no, sets the piece of the new square to the current piece
		}
		else												//if yes,
		{
			newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
			newSquare->setPiece(bptr.lock()->getPiece(id));  //sets the piece of the new square to the current piece

		}
		bptr.lock()->getPiece(id)->setPos(sq); //sets the locaiton of the current piece to the new location
	}
}



std::vector<Vec2> Piece::ray(const std::vector<Vec2>& directions)
{
	std::vector<Vec2> results;
	int size = directions.size();
	for (int d = 0; d < size; d++)
	{
		int i = 1;
		bool stop = false;
		while (!stop)
		{
			Vec2 a(pos + directions[d] * i);
			if (vacant(a))
			{
				results.push_back(a);
				i++;
			}
			else
				stop = true;
			
		}
	}
	return results;
}

