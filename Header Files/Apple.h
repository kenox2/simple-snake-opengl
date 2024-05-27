#pragma once
#include "Point.h"
#include "SnakeBody.h"
class Apple : public Point
{
public:
	int score = 0;
	Apple(int, int);
	void isEaten(SnakeBody* snake);
};

