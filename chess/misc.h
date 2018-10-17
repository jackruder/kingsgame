#pragma once
#include <iostream>
#include <vector>
using namespace std;
enum class Turn { none = 0, white, black };

enum class Pname
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

int toIndex(vector<int> a);

bool onBoard(int f, int r);
bool onBoard(vector<int> pas);


vector<int> toCoord(int i);
