#include "board.h"
#include <windows.h>
#include <vector>
#include <iostream>
int main()
{
	std::shared_ptr<Board> b = std::make_shared<Board>();
	b->starting();
	std::vector<Square> _s = b->getSquares();
	for (Square& s : _s)
	{
		std::cout << s << std::endl;
		
	}
	std::vector<Vec2> moves = b->getPiece(Pname::wpawn1)->availablemoves(b);
	for (Vec2 m : moves)
		std::cout << m << std::endl;
	int a; 
	std::cin >> a;

	return 0;

}

