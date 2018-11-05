#pragma once
#include <iostream>
#include "Vec2.h"
#include <vector>
#include <map>
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

extern std::vector<std::string> sCoords; 
enum class Coord
{
	a1,b1,c1,d1,e1,f1,g1,h1,
	a2,b2,c2,d2,e2,f2,g2,h2,
	a3,b3,c3,d3,e3,f3,g3,h3,
	a4,b4,c4,d4,e4,f4,g4,h4,
	a5,b5,c5,d5,e5,f5,g5,h5,
	a6,b6,c6,d6,e6,f6,g6,h6,
	a7,b7,c7,d7,e7,f7,g7,h7,
	a8,b8,c8,d8,e8,f8,g8,h8,
};	 

extern std::map<std::string, Coord> cMap;
extern std::map<std::string, Pname> pMap;
extern std::vector<Coord> startpos;

/* We will use integer (int datatype to save memory) indexing of a 2d grid to refer to squares. This is to keep squares close together in memory and to keep things clean.
2x2 dimensional example of this

	| 2 = (0,1) 3 = (1,1) |
	| 0 = (0,0) 1 = (1,0) |
	
	
	toIndex and toCoord implement this functionality for a 8x8 board
	*/

int toIndex(Vec2 a);  //returns the integer index location
Vec2 toCoord(int i);  //returns the actual location as a vec2
Vec2 toCoord(Coord c);


bool onBoard(int f, int r); //checks if square is on the board given two int inputs; passed by const reference
bool onBoard(Vec2 pos); //overload for a vector instead; to be passed by const reference
