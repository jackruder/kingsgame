#include "board.h"
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
		if (s.getPiece() != nullptr)
		{
			std::string d = s.getPiece()->getName();
			std::cout << "Piece: " << d << std::endl;
		}
	}
	int a; 
	std::cin >> a;

	return 0;

}

