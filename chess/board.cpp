#include "board.h" 


Board::Board()
	:	turn(Turn::none)
{
	//instantiate squares then pieces
}

Board::~Board() 
{
}

shared_ptr<Piece> Board::getPiece(Pname name) // returns pointer to piece by name
{

	return pieces[static_cast<int>(name)];
}
shared_ptr<Square> Board::getSquare(vector<int> pos)// returns pointer to square at location -- update for smart pointers
{
	return squares[pos[0]][pos[1]];
}
Turn Board::getTurn() const
{
	return turn;
}