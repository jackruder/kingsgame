#include "piece.h" 
using namespace std;


//constructor
Piece::Piece(string c, string s, shared_ptr<Board> brd, Pname i, int id)
	: color(c), name(s), bptr(brd), identifier(i), pos({})
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
void Piece::move(vector<int>& sq)
{
	vector<int> current = pos;
	Square& newSquare = bptr.lock()->getSquare(sq);

	if (!current.empty())
	{
		Square& currentSquare = bptr.lock()->getSquare(current);
		if (newSquare.getPiece() == nullptr)
		{
			newSquare.setPiece(bptr.lock()->getPiece(id));
			currentSquare.setPiece(nullptr);
		}
		else
		{
			vector<int> empty;
			newSquare.getPiece()->setPos(empty);
			newSquare.setPiece(bptr.lock()->getPiece(id));
			currentSquare.setPiece(nullptr);
		}
	}
	else
	{
		if (newSquare.getPiece() == nullptr)
		{
			newSquare.setPiece(bptr.lock()->getPiece(id));
		}
		else
		{
			vector<int> empty;
			newSquare.getPiece()->setPos(empty);
			newSquare.setPiece(bptr.lock()->getPiece(id));

		}
		setPos(sq);
	}
}

bool Piece::vacant(const vector<int>& npos)
{
	if (onBoard(npos))
	{
		shared_ptr<Board> b = bptr.lock();
		shared_ptr<Piece> p = b->getSquare(npos).getPiece();
		if (p == nullptr)
			return true;
		else if (p->getColor() == color)
			return false;
		else
			return true;
	}
	else
		return false;
}