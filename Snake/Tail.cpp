#include "Tail.h"
#include <iostream>

void Tail::initTail(int ix, int iy)
{
	int prevX = x[0];
	int prevY = y[0];
	int prev2X, prev2Y;
	x[0] = ix;
	y[0] = iy;

	for (int i = 1; i < numTeil; i++)
	{
		prev2X = x[i];
		prev2Y = y[i];
		x[i] = prevX;
		y[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
}

void Tail::printTail(int ix, int iy, bool& isPr)
{
	for (int i = 0; i < numTeil; i++)
	{
		if (x[i] == ix && y[i] == iy)
		{
			std::cout << tail;
			isPr = true;
		}
	}
}

bool Tail::tailEat(int ix, int iy)
{
	for (int i = 0; i < numTeil; i++)
	{
		if (x[i] == ix && y[i] == iy)
		{
			return true;
		}
	}
	return false;
}
