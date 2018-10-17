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
	shared_ptr<Piece> getPiece(int id);
	shared_ptr<Piece> getPiece(vector<int> loc);

	Square& getSquare(vector<int> pos); // returns reference to square at location -- takes vector or pos
	Square& getSquare(int pos);
	Turn getTurn() const;
};