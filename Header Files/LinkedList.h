#pragma once
#include "Node.h"
class LinkedList
{
	Node* head;
	Node* tail;
public:
	LinkedList(Node*);
	void add(Node*);
	Node* getTail();
	void setTail(Node*);
	Node* getHead();
};

