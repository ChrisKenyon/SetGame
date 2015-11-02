#include "stdafx.h"
#include "Deck.h"
#include <time.h>


Deck::Deck()
{
	initializeNewDeck();
}


Deck::~Deck()
{
	while (top)
		removeFromTop();
}

// randomly rearrange the deck
void Deck::Shuffle()
{
	if (top == nullptr || _count == 0)
		throw new argumentException();
	else if (_count == 1)
		return;
	else
	{
		while (_count != 0)
		{
			Card card(removeFromTop());
			vecToRandomize.push_back(card);
		}
		randomizeVector(vecToRandomize);
		Replace(vecToRandomize);
	}
}

// Deal the [num] of cards from the top of the deck to the vector [v]
void Deck::Deal(int num, vector<Card>& v)
{
	for (int i = 0; i < num; i++)
	{
		v.push_back(removeFromTop());
	}
}

// Add a vector of cards to the bottom of the deck one by one
void Deck::Replace(vector<Card>& v)
{
	int size = v.size();
	for (int i = size - 1; i >= 0; i--)
	{
		addToBottom(v[i]);
		v.pop_back();
	}
}

// initiailize the 81 cards
void Deck::initializeNewDeck()
{
	for (int w = 1; w <= 3; w++)
	{
		for (int x = 1; x <= 3; x++)
		{
			for (int y = 1; y <= 3; y++)
			{
				for (int z = 1; z <= 3; z++)
				{
					Card card(w, (Card::Symbols)x, (Card::Shadings)y, (Card::Colors)z);
					addToBottom(card);
				}
			}
		}
	}
}

// Add a new node to the bottom with the given card
void Deck::addToBottom(Card &c)
{
	Node* newNode = new Node(c);
	if (newNode == nullptr)
		throw new memoryAllocationException();
	if (&top == NULL || _count == 0)
	{
		top = newNode;
		bottom = nullptr;
	}
	else if (&top != NULL && bottom == nullptr)
	{
		top->next = newNode;
		bottom = top->next;
		bottom->next = nullptr;
	}
	else
	{
		bottom->next = newNode; // changes the ptr in the actual class
		bottom = bottom->next; // changes the bottom ptr local to deck
		bottom->next = nullptr;
	}

	_count++;
}

// remove from the top of the deck and clean up the node that was
// initialized with new by using a delete
Card Deck::removeFromTop()
{
	if (_count < 1)
		throw new indexRangeException();

	Node* removed = top;
	top = top->next;
	removed->next = nullptr;
	Card card(removed->card);
	delete removed;

	if (--_count == 0)
		bottom = nullptr;
	return card;
}

void Deck::randomizeVector(vector<Card>& v)
{
	int num = v.size();
	
	// Use different rand seed each time to make it more random
	srand(time(NULL));

	for (int i = num - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		swap(v[i], v[j]);
	}
}


