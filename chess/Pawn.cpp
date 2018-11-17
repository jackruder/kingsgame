#include "Pawn.h"
#include "board.h"
#include "square.h"

Pawn::Pawn(Color c, std::string n, int _id, Vec2 loc)
	:Piece(c, n, _id, loc)
{
	symb = c == Color::white ? 'P' : 'p';
}

Pawn::~Pawn()
{
}

std::shared_ptr<Piece> Pawn::clone()
{
	return std::make_shared<Pawn>(*this);
}


std::vector<Vec2> Pawn::availablemoves(Board* b)
{
	std::vector<Vec2> moves;
	int t;
	Vec2 d;
	if (color == Color::white)
	{
		t = 1;
		d = Vec2(0, 1);
	}
	else
	{

		t = 6;
		d = Vec2(0, -1);
	}
	int newposr = pos[1] + d[1];
	Vec2 forward1(pos[0], newposr);
	Vec2 capleft(pos[0] - 1, newposr);
	Vec2 capright(pos[0] + 1, newposr);
	Vec2 caps[2] = { capleft, capright };
	if (vacant(b, forward1))
	{
		if (b->getSquare(forward1)->getPiece() == nullptr)
		{
			moves.push_back(forward1);
			if (pos[1] == t)
			{
				Vec2 forward2(pos[0], pos[1] + 2 * d[1]);
				if (vacant(b, forward2))
				{
					if (b->getSquare(forward2)->getPiece() == nullptr)
					{
						moves.push_back(forward2);
					}
				}
			}
		}
	}
	for (Vec2 v : caps)
		if (vacant(b, v))
		{
			if (!(b->getPiece(v) == nullptr))
			{
				moves.push_back(v);
			}
			else if (!(b->getPiece(v - d) == nullptr))
			{
				if (b->getPiece(v - d)->getName() == b->getMoved2())
					moves.push_back(v);
			}
		}
	return moves;
}

std::vector<Vec2> Pawn::availablemoves(std::shared_ptr<Board> b)
{
	std::vector<Vec2> moves;
	int t;
	Vec2 d;
	if (color == Color::white)
	{
		t = 1;
		d = Vec2(0, 1);
	}
	else
	{

		t = 6;
		d = Vec2(0, -1);
	}
	int newposr = pos[1] + d[1];
	Vec2 forward1(pos[0], newposr);
	Vec2 capleft(pos[0] - 1, newposr);
	Vec2 capright(pos[0] + 1, newposr);
	Vec2 caps[2] = { capleft, capright };
	if (vacant(b, forward1))
	{
		if (b->getSquare(forward1)->getPiece() == nullptr)
		{
			moves.push_back(forward1);
			if (pos[1] == t)
			{
				Vec2 forward2(pos[0], pos[1] + 2 * d[1]);
				if (vacant(b, forward2))
				{
					if (b->getSquare(forward2)->getPiece() == nullptr)
					{
						moves.push_back(forward2);
					}
				}
			}
		}
	}
	for (Vec2 v : caps)
		if (vacant(b, v))
		{
			if (!(b->getPiece(v) == nullptr))
			{
				moves.push_back(v);
			}
			else if (!(b->getPiece(v - d) == nullptr))
			{
				if (b->getPiece(v - d)->getName() == b->getMoved2())
					moves.push_back(v);
			}
		}
	return moves;
}


void Pawn::move(Board* b, Vec2 sq) {
	
	if (abs(sq[1] - pos[1]) == 2)
		b->setMoved2(piecename);
	Vec2 dir = sq - pos;
	int dirx = dir[0];
	if (abs(toIndex(dir)) == 9 || abs(toIndex(dir)) == 7)  //if capturing diagonally
	{

		Square* inq = b->getSquare(Vec2(pos[0] + dirx, pos[1]));
		std::shared_ptr<Piece> p = inq->getPiece();
		if (!(p == nullptr))
		{
			if (p->getName() == b->getMoved2())
			{
				inq->setPiece(nullptr);
				p->setPos(Vec2(-1, -1));
			}
		}

	}
	Vec2 empty(-1, -1);   //initialize an empty location
	Vec2 current = pos;
	if (!(sq == empty))
	{
		Square* newSquare = b->getSquare(sq);  //gets the square at the new location passed to move()              
		if (!(current == empty))									//checks if the piece is on a square
		{
			Square* currentSquare = b->getSquare(current);	//gets the square the piece is on
			if (newSquare->getPiece() == nullptr)						//checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this());	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this()); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());  //sets the piece of the new square to the current piece

			}
		}
	}
	shared_from_this()->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Pawn::move(std::shared_ptr<Board> b, Vec2 sq) {
	if (abs(sq[1] - pos[1]) == 2)
		b->setMoved2(piecename);
	Vec2 dir = sq - pos;
	int dirx = dir[0];
	if (abs(toIndex(dir)) == 9 || abs(toIndex(dir)) == 7)  //if capturing diagonally
	{

		Square* inq = b->getSquare(Vec2(pos[0] + dirx, pos[1]));
		std::shared_ptr<Piece> p = inq->getPiece();
		if (!(p == nullptr))
		{
			if (p->getName() == b->getMoved2())
			{
				inq->setPiece(nullptr);
				p->setPos(Vec2(-1, -1));
			}
		}

	}
	Vec2 empty(-1, -1);   //initialize an empty location
	Vec2 current = pos;
	if (!(sq == empty))
	{
		Square* newSquare = b->getSquare(sq);  //gets the square at the new location passed to move()              
		if (!(current == empty))									//checks if the piece is on a square
		{
			Square* currentSquare = b->getSquare(current);	//gets the square the piece is on
			if (newSquare->getPiece() == nullptr)						//checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this());	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this()); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());  //sets the piece of the new square to the current piece

			}
		}
	}
	shared_from_this()->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Pawn::move(std::shared_ptr<Board> b, int sq) {
	if (abs(toVec(sq)[1] - pos[1]) == 2)
		b->setMoved2(piecename);
	Vec2 dir = toVec(sq) - pos;
	int dirx = dir[0];
	if (abs(toIndex(dir)) == 9 || abs(toIndex(dir)) == 7)  //if capturing diagonally
	{

		Square* inq = b->getSquare(Vec2(pos[0] + dirx, pos[1]));
		std::shared_ptr<Piece> p = inq->getPiece();
		if (!(p == nullptr))
		{
			if (p->getName() == b->getMoved2())
			{
				inq->setPiece(nullptr);
				p->setPos(Vec2(-1, -1));
			}
		}

	}
	int empty = -1;   //initialize an empty location
	int current = toIndex(pos);
	if (!(sq == empty))
	{
		Square* newSquare = b->getSquare(sq);  //gets the square at the new location passed to move()              
		if (!(current == empty))									//checks if the piece is on a square
		{
			Square* currentSquare = b->getSquare(current);	//gets the square the piece is on
			if (newSquare->getPiece() == nullptr)						//checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this());	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this()); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());  //sets the piece of the new square to the current piece

			}
		}
	}
	shared_from_this()->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Pawn::move(std::shared_ptr<Board> b, Coord coor) {
	if (abs(toVec(coor)[1] - pos[1]) == 2)
		b->setMoved2(piecename);
	Vec2 dir = toVec(coor) - pos;
	int dirx = dir[0];
	if (abs(toIndex(dir)) == 9 || abs(toIndex(dir)) == 7)  //if capturing diagonally
	{

		Square* inq = b->getSquare(Vec2(pos[0] + dirx, pos[1]));
		std::shared_ptr<Piece> p = inq->getPiece();
		if (!(p == nullptr))
		{
			if (p->getName() == b->getMoved2())
			{
				inq->setPiece(nullptr);
				p->setPos(Vec2(-1, -1));
			}
		}

	}
	int sq = static_cast<int>(coor);
	int empty = -1;   //initialize an empty location
	int current = toIndex(pos);
	if (!(sq == empty))
	{
		Square* newSquare = b->getSquare(sq);  //gets the square at the new location passed to move()              
		if (!(current == empty))									//checks if the piece is on a square
		{
			Square* currentSquare = b->getSquare(current);	//gets the square the piece is on
			if (newSquare->getPiece() == nullptr)						//checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this());	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this()); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());  //sets the piece of the new square to the current piece

			}
		}
	}
	shared_from_this()->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Pawn::move(Board* b, int sq) {
	
	if (abs(toVec(sq)[1] - pos[1]) == 2)
		b->setMoved2(piecename);
	Vec2 dir = toVec(sq) - pos;
	int dirx = dir[0];
	if (abs(toIndex(dir)) == 9 || abs(toIndex(dir)) == 7)  //if capturing diagonally
	{

		Square* inq = b->getSquare(Vec2(pos[0] + dirx, pos[1]));
		std::shared_ptr<Piece> p = inq->getPiece();
		if (!(p == nullptr))
		{
			if (p->getName() == b->getMoved2())
			{
				inq->setPiece(nullptr);
				p->setPos(Vec2(-1, -1));
			}
		}

	}
	int empty = -1;   //initialize an empty location
	int current = toIndex(pos);
	if (!(sq == empty))
	{
		Square* newSquare = b->getSquare(sq);  //gets the square at the new location passed to move()              
		if (!(current == empty))									//checks if the piece is on a square
		{
			Square* currentSquare = b->getSquare(current);	//gets the square the piece is on
			if (newSquare->getPiece() == nullptr)						//checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this());	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this()); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());  //sets the piece of the new square to the current piece

			}
		}
	}
	shared_from_this()->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Pawn::move(Board* b, Coord coor) {
	if (abs(toVec(coor)[1] - pos[1]) == 2)
		b->setMoved2(piecename);
	Vec2 dir = toVec(coor) - pos;
	int dirx = dir[0];
	if (abs(toIndex(dir)) == 9 || abs(toIndex(dir)) == 7)  //if capturing diagonally
	{

		Square* inq = b->getSquare(Vec2(pos[0] + dirx, pos[1]));
		std::shared_ptr<Piece> p = inq->getPiece();
		if (!(p == nullptr))
		{
			if (p->getName() == b->getMoved2())
			{
				inq->setPiece(nullptr);
				p->setPos(Vec2(-1, -1));
			}
		}

	}
	int sq = static_cast<int>(coor);
	int empty = -1;   //initialize an empty location
	int current = toIndex(pos);
	if (!(sq == empty))
	{
		Square* newSquare = b->getSquare(sq);  //gets the square at the new location passed to move()              
		if (!(current == empty))									//checks if the piece is on a square
		{
			Square* currentSquare = b->getSquare(current);	//gets the square the piece is on
			if (newSquare->getPiece() == nullptr)						//checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this());	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(shared_from_this()); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(shared_from_this());  //sets the piece of the new square to the current piece

			}
		}
	}
	shared_from_this()->setPos(sq); //sets the locaiton of the current piece to the new location
}


