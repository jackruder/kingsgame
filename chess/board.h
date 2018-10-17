#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "square.h"
#include "misc.h"
#include "piece.h"
using namespace std;

class Piece;

class Board
{

private:
	void genSquares();
	Turn turn; // none, white, black enum
	vector<shared_ptr<Piece>> pieces; // container of pointers to pieces
	vector<Square> squares; //  2d container of squares
public:

	Board();

	~Board();

	shared_ptr<Piece> getPiece(Pname name); // returns pointer to piece given enum name, vec location, or int ID
	shared_ptr<Piece> getPiece(int id);  // overload for ID (see misc.h)
	shared_ptr<Piece> getPiece(vector<int> loc);  //overload for loc
	void move(shared_ptr<Piece> p, vector<int>& sq); //moves a piece at pointer p to vector location sq, making sure to update all pieces and squares involved
	Square& getSquare(vector<int> pos); // returns reference to square at location -- takes vector or pos.  reference returned since we don't want a square copy
	Square& getSquare(int id);  //overload for ID (see misc.h)
	Turn getTurn() const;
};