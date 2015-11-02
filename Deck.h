#pragma once

#include "Card.h"
#include "Node.h"
#include <vector>

class Deck
{
public:
	Deck();
	~Deck();
	void Shuffle();
	void Deal(int num, vector<Card> &v);
	void Replace(vector<Card> &v);
private:
	// private class data
	vector<Card> vecToRandomize;
	Node* top;
	Node* bottom;
	int _count;

	// private functions [see comments in .cpp]
	void initializeNewDeck();
	void addToBottom(Card &c);
	Card removeFromTop();
	void randomizeVector(vector<Card> &v);
};

