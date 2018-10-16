#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "misc.h"
using namespace std;

class Piece;
class Square;
class Board 
{
	public:
		
		Board();

		~Board();

		shared_ptr<Piece> getPiece(Pname name); // returns pointer to piece at location -- update for smart pointers
		shared_ptr<Square> getSquare(vector<int> pos); // returns pointer to square at location -- update for smart pointers
		Turn getTurn() const;
	private:
		
		Turn turn; // none, white, black enum
		vector<shared_ptr<Piece>> pieces; // container of pointers to pieces
		vector<vector<shared_ptr<Square>>> squares; //  2d container of pointers to squares
};