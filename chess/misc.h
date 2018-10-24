#pragma once
#include <iostream>
#include "Vec2.h"
#include <vector>
enum class Turn : int { none = 0, white, black };

enum class Pname //reorder these to correspond to order of instantiation
{
	wrook1,
	wrook2,
	wbishop1,
	wbishop2,
	wknight1,
	wknight2,
	wking1,
	wqueen1,
	wpawn1,
	wpawn2,
	wpawn3,
	wpawn4,
	wpawn5,
	wpawn6,
	wpawn7,
	wpawn8,
	brook1,
	brook2,
	bbishop1,
	bbishop2,
	bknight1,
	bknight2,
	bking1,
	bqueen1,
	bpawn1,
	bpawn2,
	bpawn3,
	bpawn4,
	bpawn5,
	bpawn6,
	bpawn7,
	bpawn8,

};

extern std::vector<int> startpos;

/* We will use integer (int datatype to save memory) indexing of a 2d grid to refer to squares. This is to keep squares close together in memory and to keep things clean.
2x2 dimensional example of this

	| 2 = (0,1) 3 = (1,1) |
	| 0 = (0,0) 1 = (1,0) |
	
	
	toIndex and toCoord implement this functionality for a 8x8 board
	*/

int toIndex(Vec2 a);  //returns the integer index location
Vec2 toCoord(int i);  //returns the actual location as a vec2

bool onBoard(int f, int r); //checks if square is on the board given two int inputs; passed by const reference
bool onBoard(Vec2 pos); //overload for a vector instead; to be passed by const reference
