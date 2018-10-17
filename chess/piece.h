#pragma once
#include <iostream> 
#include <vector>
#include <memory>
#include "misc.h"
#include "board.h"
using namespace std;
class Board;


class Piece 
{
	public:
		
		Piece(string c, string n, shared_ptr<Board> brd, Pname i, int id);
		int getId() const;
		char getSymb() const;
		string getColor() const;
		string getName() const;
		vector<int> getPos();
		weak_ptr<Board> getBoardPtr() const; 
		void setPos(vector<int> p);  


	protected:
		
		int id;
		string color;
		string name;
		vector<int> pos; // Pieces should be initialized with no location, which will be a nullptr
		char symb;
		weak_ptr<Board> bptr; // weak_ptr because piece does not own board: we don't want an increase in refrence count 
		Pname identifier;
		bool vacant(const vector<int>& npos);  //checks if a square is allowed, regardless of check, turn, etc,.
		vector<vector<int>> ray(vector<vector<int>> directions);
};
