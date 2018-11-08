#include "piece.h" 


//constructor
Piece::Piece(Color c, std::string n, int i, Vec2 loc)
	: color(c), piecename(n), id(i), pos(loc)
{

}

Piece::~Piece()
{
}

// Getter functions
std::string Piece::getName() const 
{
	return piecename;
}

Color Piece::getColor() const
{
	return color;
}

int Piece::getID()
{
	return id;
}

char Piece::getSymb() const
{
	return symb;
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
	pos = toVec(p);
}

std::ostream &operator<<(std::ostream &output, const Piece& p)
{
	output << "Piece: " << p.piecename;
	return output;
}

// Member Functions

bool Piece::vacant(Board* b, Vec2 npos)  //checks if a square is allowed, regardless of check, turn, etc,.
{
	if (onBoard(npos))
	{
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

bool Piece::vacant(std::shared_ptr<Board> b, Vec2 npos)  //checks if a square is allowed, regardless of check, turn, etc,.
{
	if (onBoard(npos))
	{
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


void Piece::move(Board* b, Vec2 sq) {
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
				newSquare->setPiece(b->getPiece(id));	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(b->getPiece(id)); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));  //sets the piece of the new square to the current piece

			}
		}
	}
	b->getPiece(id)->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Piece::move(std::shared_ptr<Board> b, Vec2 sq) {
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
				newSquare->setPiece(b->getPiece(id));	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(b->getPiece(id)); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));  //sets the piece of the new square to the current piece

			}
		}
	}
	b->getPiece(id)->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Piece::move(std::shared_ptr<Board> b, int sq) {
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
				newSquare->setPiece(b->getPiece(id));	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(b->getPiece(id)); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));  //sets the piece of the new square to the current piece

			}
		}
	}
	b->getPiece(id)->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Piece::move(std::shared_ptr<Board> b, Coord coor) {
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
				newSquare->setPiece(b->getPiece(id));	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(b->getPiece(id)); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));  //sets the piece of the new square to the current piece

			}
		}
	}
	b->getPiece(id)->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Piece::move(Board* b, int sq) {
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
				newSquare->setPiece(b->getPiece(id));	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(b->getPiece(id)); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));  //sets the piece of the new square to the current piece

			}
		}
	}
	b->getPiece(id)->setPos(sq); //sets the locaiton of the current piece to the new location
}

void Piece::move(Board* b, Coord coor) {
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
				newSquare->setPiece(b->getPiece(id));	//if no piece, we just set the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//then set the piece of the old square to none
			}
			else												//if there is a piece
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));	//sets the piece of the new square to the current piece
				currentSquare->setPiece(nullptr);				//sets the piece of the old square to none
			}
		}
		else                                                 //if the piece is not on a square
		{
			if (newSquare->getPiece() == nullptr)  //checks if the new square has a piece
			{
				newSquare->setPiece(b->getPiece(id)); // if no, sets the piece of the new square to the current piece
			}
			else												//if yes,
			{
				newSquare->getPiece()->setPos(empty);			//this is a capture, so piece at new square now has no location
				newSquare->setPiece(b->getPiece(id));  //sets the piece of the new square to the current piece

			}
		}
	}
	b->getPiece(id)->setPos(sq); //sets the locaiton of the current piece to the new location
}

std::vector<Vec2> Piece::ray(Board* b, const std::vector<Vec2>& directions)
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
			if (vacant(b,a))
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

std::vector<Vec2> Piece::ray(std::shared_ptr<Board> b, const std::vector<Vec2>& directions)
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
			if (vacant(b, a))
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
