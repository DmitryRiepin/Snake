#pragma once
#include <iostream>
#include <ctime>

class Fruit
{
private:
	int x, y;
	const char fruit = 'F';
	

public:
	Fruit() {};
	void setX(int ix) { srand(time(0)); x = 1 + rand() % (ix - 1); };
	void setY(int iy) { srand(time(0)); y = 1 + rand() % (iy - 1); };
	int getX() { return x; }
	int getY() { return y; }

	void printFruit() { std::cout << fruit; }
};

