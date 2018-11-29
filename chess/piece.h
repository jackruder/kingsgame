#pragma once
#include <iosfwd> 
#include <vector>
#include <memory>
#include "superptr.h"
#include "misc.h"
#include "Vec2.h"
#include <string>
class Board;


class Piece : public std::enable_shared_from_this<Piece> 
{
	
public:
	Piece(Color c, std::string n, int i, Vec2 loc); 

	~Piece();
	int getID();
	char getSymb() const;
	Color getColor() const;
	std::string getName() const;

	Vec2 getPos();
	void setPos(Vec2 p);
	void setPos(int p);
	virtual void move(Board* b, Vec2 sq);
	virtual void move(std::shared_ptr<Board> b, Vec2 sq);
	virtual void move(std::shared_ptr<Board> b, int sq);
	virtual void move(std::shared_ptr<Board> b, Coord coor);
	virtual void move(Board * b, int sq);
	virtual void move(Board * b, Coord coor);
	friend std::ostream &operator<<(std::ostream &output, const Piece& p);
	std::vector<Vec2> legalMoves(Board * b);
	std::vector<Vec2> legalMoves(std::shared_ptr<Board> b);
	virtual std::vector<Vec2> availablemoves(Board *b) = 0;
	virtual std::vector<Vec2> availablemoves(std::shared_ptr<Board> b) = 0;
	virtual superptr<Piece> clone()= 0;
protected:
	
	int id;
	Color color;
	const std::string piecename;
	Vec2 pos; // Pieces should be initialized with no location, which will be a nullptr
	char symb;
	bool vacant(Board* b, Vec2 npos);  //checks if a square is allowed, regardless of check, turn, etc,.
	bool vacant(std::shared_ptr<Board> b, Vec2 npos);
	std::vector<Vec2> ray(Board *b, const std::vector<Vec2>& directions);
	std::vector<Vec2> ray(std::shared_ptr<Board> b, const std::vector<Vec2>& directions);
	
	

};
