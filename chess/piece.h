#pragma once
#include <iostream> 
#include <vector>
#include <memory>
#include "misc.h"
using namespace std;
class Board;


class Piece 
{
	public:
		
		Piece(string c, string s, shared_ptr<Board> brd, Pname i);
		char getSymb() const;
		string getColor() const;
		string getName() const;
		vector<int> getPos() const;
		weak_ptr<Board> getBoardPtr() const; 

	private:
		
		string color;
		string name;
		vector<int> pos; // Pieces should be initialized with no location, which will be called  {-1,-1}
		char symb;
		weak_ptr<Board> bptr; // forward declaration to avoid circular dependencies; this needs to be a smart pointer 
		Pname identifier;


		static bool onboard(vector<int> pos);
};
