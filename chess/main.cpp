#include "board.h"
#include <windows.h>
#include <vector>
#include <iostream>
int main()
{
	std::shared_ptr<Board> b = std::make_shared<Board>();
	b->starting();
	std::vector<Square> _s = b->getSquares();	
	bool stop = false;
	
	while (!stop)
	{
		system("cls");
		b->printBoard();
		std::cout << "(q)uit (m)ove (r)eset" << std::endl;
		
		char query;
		std::cin >> query;
		
		
		if (query == 'q')
			stop = true;
		else if (query == 'm')
		{
			std::vector<Vec2> moves;
			std::string name;
			bool isCoord = false;
			bool isPname = false;
			bool canMove = false;
			bool validMove = false;
			while (!canMove)
			{
				std::cout << "Enter a Piece/Square or (c)ancel:";
				std::cin >> name;
				isPname = pMap.find(name) != pMap.end();
				isCoord = cMap.find(name) != cMap.end();
				if (isPname) //if valid piecename
				{
					moves = b->getPiece(pMap[name])->availablemoves(b);
				}
				else if (isCoord) {  //if valid algebraic square name
					
					moves = b->getSquare(static_cast<int>(cMap[name]))->getPiece()->availablemoves(b);
				}
				else if (name == "c")
				{
					canMove = true;  //skips while loops
					validMove = true;
				}
				else
				{
					std::cout << "Invalid Piece/Square, would you like to try another? (y or n)" << std::endl;
					std::string tryagain;
					std::cin >> tryagain;
					if (tryagain == "n")
					{
						canMove = true; //skips while loops
						validMove = true;
					}
				}


				if (moves.size() != 0)
				{
					std::cout << "Available Moves (excluding check and en passant) :";
					for (Vec2 m : moves)
						std::cout << sCoords[toIndex(m)] << ", ";
					canMove = true;
				}
				else
				{
					std::cout << "No available moves" << std::endl;
				}
			}

			while (!validMove)
			{
				std::cout << std::endl << "Please enter a move or (c)ancel: " << std::endl;
				std::string smove;
				std::cin >> smove;
				Coord move = cMap[smove];
				if (std::find(moves.begin(), moves.end(), toCoord(move)) != moves.end())
				{
					if (isCoord)
					{
						b->getSquare(static_cast<int>(cMap[name]))->getPiece()->move(b, move);
						validMove = true;
					}
					else if (isPname)
					{
						b->getPiece(pMap[name])->move(b, move);
						validMove = true;
					}

				}
				else if (smove == "c")
				{
					validMove = true;
				}
				else
				{
					std::cout << "Invalid move, would you like to try another? (y or n)" << std::endl;
					std::string tryagain;
					std::cin >> tryagain;
					if (tryagain == "n")
						validMove = true;
				}
			}
		}
		else if (query == 'r')
		{
			std::string sure;
			std::cout << "Are you sure you want to reset? (y or n)" << std::endl;
			std::cin >> sure;
			if (sure == "y")
				b->starting();
		}	
		else 
			std::cout << "Please enter a valid character" << std::endl;		
	}


	return 0;

}

