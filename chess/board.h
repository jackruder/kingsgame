#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "square.h"
#include "misc.h"
#include "piece.h"

class Piece;

class Board
{

private:
	void genSquares();
	Color turn; // none, white, black enum
	std::vector<std::shared_ptr<Piece>> pieces; // container of pointers to pieces
	std::vector<Square> squares; //  2d container of squares
	void genPieces();

	void setTurn(Color t);

public:

	Board();
	Board(const Board& b); // no direct copying, use assignment operator instead (no way to deep copy pieces updating piece.bptr to newly constructed smart pointer board, since object construction occurs before pointer)
	Board& operator=(const Board& b);

	~Board();
	std::vector<Square> getSquares() const;
	std::vector<std::shared_ptr<Piece>> getPieces() const;
	std::shared_ptr<Piece> getPiece(Pname name);// returns pointer to piece given enum name, vec location, or int ID
	std::shared_ptr<Piece> getPiece(int _id);  // overload for ID (see misc.h)
	std::shared_ptr<Piece> getPiece(Vec2 loc);  //overload for loc
	void move(std::shared_ptr<Piece> p, Vec2 sq); //moves a piece at pointer p to std::vector location sq, making sure to update all pieces and squares involved
	Square* getSquare(Vec2 loc); // returns reference to square at location -- takes std::vector or pos.  reference returned since we don't want a square copy
	Square* getSquare(int _id);  //overload for ID (see misc.h)
	Color getTurn() const;

	std::vector<Coord> getPosition() const;

	void setPosition(std::vector<Coord> position, Color t); //sets the board to a specific position, see example startpos in misc.h
	void starting(); //sets the board to starting position

	void printBoard();	
	void printLine(int iLine, int iColor1, int iColor2, int cell);
	void updateSquares();
	
	bool inCheck(Color c);
	void nextTurn();
};