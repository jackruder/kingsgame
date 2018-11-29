#pragma once
#include <iosfwd>
#include <memory>
#include "superptr.h"
#include <vector>
#include <string>
#include "misc.h"



class Square;
class Piece;


class Board
{

private:
	void genSquares();
	Color turn; // none, white, black enum
	std::vector<superptr<Piece>> pieces; // container of pointers to pieces
	std::vector<Square> squares; //  2d container of squares
	void genPieces();
	std::string moved2;
	void setTurn(Color t);

public:

	Board();
	Board(const Board& b); // no direct copying, use assignment operator instead (no way to deep copy pieces updating piece.bptr to newly constructed smart pointer board, since object construction occurs before pointer)
	Board& operator=(const Board& b);

	~Board();
	std::vector<Square> getSquares() const;
	std::vector<superptr<Piece>> getPieces() const;
	superptr<Piece> getPiece(Pname name);// returns pointer to piece given enum name, vec location, or int ID
	superptr<Piece> getPiece(int _id);  // overload for ID (see misc.h)
	superptr<Piece> getPiece(Vec2 loc);  //overload for loc
	std::string getMoved2() const;
	void setMoved2(std::string p);
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
	bool checkmate();	

	std::vector<std::vector<Coord>> allMoves();
	void nextTurn();
		
	void promote(superptr<Piece> p, std::string c);

};