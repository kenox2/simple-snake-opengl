#pragma once 
#include "BodyPart.h"
class Node
{
public:
	BodyPart val;
	Node* next;
	Node* previous;

	Node(BodyPart, Node* = nullptr, Node*  = nullptr);
};

