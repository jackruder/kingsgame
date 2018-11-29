#include "board.h"
#include "square.h"
#include "piece.h"
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
			superptr<Piece> p;
			while (!canMove)
			{
				std::cout << "Enter a Piece/Square or (c)ancel:";
				std::cin >> name;
				isPname = pMap.find(name) != pMap.end();
				isCoord = cMap.find(name) != cMap.end();
				if (isPname) //if valid piecename
				{
					p = b->getPiece(pMap[name]);
						moves = p->legalMoves(b);
				}
				else if (isCoord) {  //if valid algebraic square name
				
					p = b->getSquare(static_cast<int>(cMap[name]))->getPiece();
					if (!(p == nullptr))
						moves = p->legalMoves(b);
	
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
					std::cout << "Available Moves (excluding promotion) :";
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
				Vec2 vmove = toVec(move);
				if (std::find(moves.begin(), moves.end(), vmove) != moves.end())
				{
					p->move(b, vmove);
						
					char pty = p->getSymb();
					if (pty == 'p' || pty == 'P')
					{
						if (vmove[1] == 7 || vmove[1] == 0)
						{
							bool validpromo = false;
							while (!validpromo)
							{
								std::string promo;
								std::cout << "(q)ueen, (k)night, (r)ook, (b)ishop : ";
								std::cin >> promo;
								if (promo == "q" || promo == "k" || promo == "r" || promo == "b")
								{
									b->promote(p, promo);
									validpromo = true;
								}
								else
								{
									std::cout << "Please enter a valid character" << std::endl;
								}
							}
								
						}
					}
					b->nextTurn();
					std::cout << "Looking to see if " << (b->getTurn() == Color::white ? "white" : "black") << " is in check";			
					if (b->inCheck(b->getTurn()) == true)
					{
						std::cout << "Check, enter a char to continue" << std::endl;
					}
					validMove = true;

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