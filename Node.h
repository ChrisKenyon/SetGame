#pragma once
#include "Card.h"
class Node
{
public:
	Node(Card card);
	~Node();
	Card card;
	Node* next;
};

