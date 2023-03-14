#pragma once


class Tail
{
private:
	int x[100], y[100];
	int numTeil = 0;
	const char tail = 'o';

public:
	void setTail(int num) { numTeil = num; }
	void addTail() { ++numTeil; }
	void initTail(int ix, int iy);
	void printTail(int ix, int iy, bool& isPr);

	bool tailEat(int ix, int iy);

};

