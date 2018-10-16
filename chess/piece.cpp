#include "piece.h" 
using namespace std;
// Member Functions
bool Piece::onboard(vector<int> pos) 
{
	int f = pos[0];
	int r = pos[1];
	if (f >= 0 && f < 8 && r < 8 && r >= 0) {
		return true;
	}
	else {
		return false;
	}
}
//constructor
Piece::Piece(string c, string s, shared_ptr<Board> brd, Pname i)
	: color(c), name(s), bptr(brd), identifier(i)
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

char Piece::getSymb() const
{
	return symb;
}

weak_ptr<Board> Piece::getBoardPtr() const
{
	return bptr;
}

vector<int> Piece::getPos() const
{
	return pos;
}
