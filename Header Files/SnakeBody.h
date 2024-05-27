#pragma once
#include "LinkedList.h"

class SnakeBody
{
public:
	LinkedList* list;
	char dir = 'R';

	SnakeBody(LinkedList* list);
	void growSnake();
	void move();
	void collision(bool &);
};

