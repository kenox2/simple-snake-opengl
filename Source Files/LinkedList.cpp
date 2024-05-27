#include "LinkedList.h"


LinkedList::LinkedList(Node* n) : head(n), tail(n){
} 

void LinkedList::add(Node* x) {
	tail->next = x;
	tail = x;
}

Node* LinkedList::getTail() {
	return tail;
}

void LinkedList::setTail(Node* x) {
	tail = x;
}

Node* LinkedList::getHead() {
	return head;
}