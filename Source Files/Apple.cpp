#include "Apple.h"
#include<cstdlib>
#include<iostream>
Apple::Apple(int x, int y) : Point(x, y) {}

void Apple::isEaten(SnakeBody* snake) {

	std::cout << "Position apple: " << x << ", " << y << std::endl;
	std::cout << "X: " << snake->list->getHead()->val.x + 1 << " Y: " << snake->list->getHead()->val.y + 1 << std::endl;
	if (snake->list->getHead()->val.x + 1 == x && snake->list->getHead()->val.y + 1== y) {
		snake->growSnake();

		//calcualte new coords for apple
		
		srand((unsigned)time(NULL));

		
		x = rand()%20 + 1;
		y = rand()%20 + 1;

		score++;
	}
	
}