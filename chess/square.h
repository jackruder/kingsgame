#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "misc.h"
using namespace std;
class Piece;

class Square
{
public:
	Square(string n, string c, vector<int> pos);
	~Square();
	string getName() const;
	string getColor() const;
	shared_ptr<Piece> getPiece() const;
	vector<int> getPos() const;
	
	void setPiece(shared_ptr<Piece> p);

private:
	string name;
	string color;
	shared_ptr<Piece> piece;
	vector<int> pos;
};

