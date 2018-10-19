#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "square.h"
#include "misc.h"
#include "piece.h"

class Piece;

class Board
{

private:
	void genSquares();
	Turn turn; // none, white, black enum
	std::vector<std::shared_ptr<Piece>> pieces; // container of pointers to pieces
	std::vector<Square> squares; //  2d container of squares
public:

	Board();

	~Board();

	std::shared_ptr<Piece> getPiece(Pname name); // returns pointer to piece given enum name, vec location, or int ID
	std::shared_ptr<Piece> getPiece(int id);  // overload for ID (see misc.h)
	std::shared_ptr<Piece> getPiece(Vec2 loc);  //overload for loc
	void move(std::shared_ptr<Piece> p, Vec2& sq); //moves a piece at pointer p to std::vector location sq, making sure to update all pieces and squares involved
	Square& getSquare(Vec2 pos); // returns reference to square at location -- takes std::vector or pos.  reference returned since we don't want a square copy
	Square& getSquare(int id);  //overload for ID (see misc.h)
	Turn getTurn() const;
};