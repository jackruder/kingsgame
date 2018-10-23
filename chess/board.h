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
	Turn turn; // none, white, black enum
	std::vector<std::shared_ptr<Piece>> pieces; // container of pointers to pieces
	std::vector<std::shared_ptr<Square>> squares; //  2d container of squares
public:

	Board();
	Board(const Board& b) = delete; // no copying, use assignment operator instead (no way to deep copy pieces updating piece.bptr to newly constructed smart pointer board, since object construction occurs before pointer)

	~Board();
	std::vector<std::shared_ptr<Square>> getSquares() const;
	std::vector<std::shared_ptr<Piece>> getPieces() const;
	std::shared_ptr<Piece> getPiece(Pname name) const; // returns pointer to piece given enum name, vec location, or int ID
	std::shared_ptr<Piece> getPiece(int id) const;  // overload for ID (see misc.h)
	std::shared_ptr<Piece> getPiece(Vec2 loc) const;  //overload for loc
	void move(std::shared_ptr<Piece> p, Vec2 sq); //moves a piece at pointer p to std::vector location sq, making sure to update all pieces and squares involved
	std::shared_ptr<Square> getSquare(Vec2 pos) const; // returns reference to square at location -- takes std::vector or pos.  reference returned since we don't want a square copy
	std::shared_ptr<Square> getSquare(int id) const;  //overload for ID (see misc.h)
	Turn getTurn() const;
};