#include "SnakeBody.h"
#include <iostream>

SnakeBody::SnakeBody(LinkedList* list) : list(list) {

}
void SnakeBody::growSnake() {
	BodyPart part = list->getTail()->val;
	Node* ptr = new Node(part);
	list->getTail()->next = ptr;
	ptr->previous = list->getTail();
	list->setTail(ptr);
	
}

void SnakeBody::move() {
	Node* head = list->getHead();
	
	Node* tail = list->getTail();
	Node* curr = tail;

	while (curr != head)
	{
		if (curr != head ) {
			curr->val = curr->previous->val;
		}
		

		curr = curr->previous;
	}



	
	if (dir == 'R') {
		head->val.x += 1;
	}
	else if (dir == 'L') {
		head->val.x -= 1;
	}
	else if (dir == 'U') {
		head->val.y += 1;
	}
	else {
		head->val.y -= 1;
	}

	


}


void SnakeBody::collision(bool &isGameOver) {
	Node* head = list->getHead();
    
	//hitting walls
	if (head->val.x < 0 || head->val.x > 20 || head->val.y < 0 || head->val.x > 20) {
		isGameOver = true;
	}
	//hitting body

	Node* curr = head->next;
	while (curr != nullptr) {

		if (curr->val.x == head->val.x && curr->val.y == head->val.y) {
			isGameOver = true;
			break;
		}
		curr = curr->next;
	}
}