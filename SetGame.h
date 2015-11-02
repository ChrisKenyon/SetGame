#pragma once

#include "Deck.h"

class SetGame
{
public:
	SetGame();
	~SetGame();
	void playSet();
private:
	const int NUMBER_OF_CARDS = 12;
	Deck gameDeck;

	// private functions [see .cpp for comments]
	void printCards(const vector<Card> &v) const;
	vector<vector<Card>> findAllSets(vector<Card>& cards, bool print);
	void printSet(vector<Card>& c);
	bool isASet(vector<Card>& c);
	void findLargestNonSet();
};

