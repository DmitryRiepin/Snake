#include "Game.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>

void Game::startGame()
{
	score = 0;
	key = STOP;
	head.setX(with / 2);
	head.setY(hight / 2);

	fruit.setX(with);
	fruit.setY(hight);

	tail.setTail(0);

	do
	{
		draw();
		logics();
		move();		

		Sleep(10);

	} while (!finishGame);

}

void Game::draw()
{
	system("cls");
	std::cout << std::endl;

	for (int i = 0; i <= hight; i++)
	{
		for (int j = 0; j <= with; j++)
		{
			if (i == 0 || i == hight)
			{
				std::cout << '+';
			}
			else if (j == 0 || j == with)
			{
				std::cout << '+';
			}
			else if (j == fruit.getX() && i == fruit.getY())
			{
				fruit.printFruit();
			}
			else if (j == head.getX() && i == head.getY())
			{
				head.printHead();
			}
			else
			{
				bool a = false;
				tail.printTail(j, i, a);

				if (!a)
					std::cout << ' ';
			}

		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "SCORE: " << score << std::endl;
}

void Game::logics()
{
	tail.initTail(head.getX(), head.getY());

	switch (key)
	{
	case STOP:
		break;
	case UP:
		head.minusY();
		break;
	case DOWN:
		head.addY();
		break;
	case LEFT:
		head.minusX();
		break;
	case RIGHT:
		head.addX();
		break;
	}

	if (head.getX() == fruit.getX() && head.getY() == fruit.getY())
	{
		score += 10;
		fruit.setX(with);
		fruit.setY(hight);

		tail.addTail();
	}
	if (tail.tailEat(head.getX(), head.getY()))
	{
		gameOver();
	}

	if (head.getX() == with)
	{
		head.setX(1);
	}
	else if (head.getX() == 0)
	{
		head.setX(with - 1);
	}
	else if (head.getY() == hight)
	{
		head.setY(1);
	}
	else if (head.getY() == 0)
	{
		head.setY(hight - 1);
	}
}

void Game::move()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			key = LEFT;
			break;
		case 'd':
			key = RIGHT;
			break;
		case 'w':
			key = UP;
			break;
		case 's':
			key = DOWN;
			break;
		case 'y':
			gameOver();
			break;
		}
	}
}

void Game::gameOver() 
{
	finishGame = true;

	system("cls");

	std::cout << "Reapite game? \t" << "y/n" << std::endl;

	switch (_getch())
	{
	case 'y':
		finishGame = false;
		startGame();
		break;
	default:
		break;
	}
}
