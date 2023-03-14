#pragma once


class Head
{
private:
	int x, y;
	const char head = 'O';

public:
	Head();
	//Head(int ix, int iy) { x = ix; y = iy; };

	void printHead();

	void addX() { x++; }
	void addY() { y++; }
	void minusX() { x--; }
	void minusY() { y--; }

	void setX(int ix) { x = ix; };
	void setY(int iy) { y = iy; };
	int getX() { return x; }
	int getY() { return y; }
};

