#pragma once

#include "Tail.h"
#include "Head.h"
#include "Fruit.h"



enum keyInput
{
	STOP,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Game
{
private:
	const int with = 40;
	const int hight = 20;
	keyInput key = STOP;
	bool finishGame = false;

	Head head;
	Tail tail;
	Fruit fruit;

	int score;

public:
	void gameOver();

	void startGame();
	void draw();
	void logics();
	void move();



};

