#pragma once
#include <iostream> 
#include <vector>
#include <memory>
#include "misc.h"
#include "Vec2.h"
#include "board.h"

class Board;


class Piece 
{
	public:
		
		Piece(std::string c, std::string n, std::shared_ptr<Board> brd, Pname i, int id);
		int getId() const;
		int getSymb() const;
		std::string getColor() const;
		std::string getName() const;
		Vec2 getPos();
		std::weak_ptr<Board> getBoardPtr() const; 
		void setPos(Vec2 p);  


	protected:
		
		int id;
		std::string color;
		std::string name;
		Vec2 pos; // Pieces should be initialized with no location, which will be a nullptr
		int symb;
		std::weak_ptr<Board> bptr; // weak_ptr because piece does not own board: we don't want an increase in refrence count 
		Pname identifier;
		bool vacant(const Vec2& npos);  //checks if a square is allowed, regardless of check, turn, etc,.
		//std::vector<Vec2> ray(std::vector<Vec2> directions);
};
