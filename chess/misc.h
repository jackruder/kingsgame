#pragma once
#include <iostream>
#include <vector>
using namespace std;
enum class Turn { none = 0, white, black };

enum class Pname //reorder these to correspond to order of instantiation
{
	wrook1,
	wknight1,
	wbishop1,
	wqueen1,
	wking1,
	wbishop2,
	wknight2,
	wrook2,
	wpawn1,
	wpawn2,
	wpawn3,
	wpawn4,
	wpawn5,
	wpawn6,
	wpawn7,
	wpawn8,
	brook1,
	bknight1,
	bbishop1,
	bqueen1,
	bking1,
	bbishop2,
	bknight2,
	brook2,
	bpawn1,
	bpawn2,
	bpawn3,
	bpawn4,
	bpawn5,
	bpawn6,
	bpawn7,
	bpawn8
};
/* We will use integer indexing of a 2d grid to refer to squares. This is to keep squares close together in memory and to keep things clean.
2x2 dimensional example of this

	| 2 = (0,1) 3 = (1,1) |
	| 0 = (0,0) 1 = (1,0) |
	
	
	toIndex and toCoord implement this functionality for a 8x8 board
	*/


int toIndex(const vector<int> &a);  //returns the integer index location
vector<int> toCoord(int i);  //returns the actual location as a vector<int>

bool onBoard(int f, int r); //checks if square is on the board given two int inputs; passed by const reference
bool onBoard(const vector<int>& pas); //overload for a vector instead; to be passed by const reference
