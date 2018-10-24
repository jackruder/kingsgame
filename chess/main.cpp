#include "board.h"
#include <vector>
#include <iostream>
int main()
{
	std::shared_ptr<Board> b = std::make_shared<Board>();
	b->getPiece(4);
	int a; 
	std::cin >> a;

	return 0;

}

