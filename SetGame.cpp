#include "stdafx.h"
#include "SetGame.h"


SetGame::SetGame()
{
}

SetGame::~SetGame()
{
}

// start the game of set
void SetGame::playSet()
{
	vector<Card> cards;
	gameDeck.Shuffle();
	gameDeck.Deal(NUMBER_OF_CARDS, cards);

	printCards(cards);
	findAllSets(cards, true).clear();
	gameDeck.Replace(cards);

	// Uncomment this but note that it will run long and probably not succeed!
	// findLargestNonSet();
}

// prints the vector of cards
void SetGame::printCards(const vector<Card>& v) const
{
	if (v.size() < 1)
		throw new argumentException();

	cout << "The dealt cards are:" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;
}

// returns a vector of vectors of 3 cards
vector<vector<Card>> SetGame::findAllSets(vector<Card> &cards, bool print)
{
	if (cards.size() < 3)
		throw new argumentException();

	int numCards = cards.size();
	vector<vector<Card>> sets;

	// for any two cards, only one other card will make it a set
	for (int first = 0; first < numCards - 2; first++)
	{
		for (int second = 1 + first; second < numCards - 1; second++)
		{
			for (int third = 1 + second; third < numCards; third++)
			{
				vector<Card> set({ cards[first], cards[second], cards[third] });
				if (isASet(set))
				{
					sets.push_back(set);
					if (print) printSet(set);
				}
			}
		}
	}
	if (print) 
		printf("\nFound %i sets!\n", sets.size());
	return sets;
}

void SetGame::printSet(vector<Card> &c)
{
	if (c.size() < 3)
		throw new argumentException();

	cout << "Set of:\n" << c[0] << c[1] << c[2];
}

bool SetGame::isASet(vector<Card> &c)
{
	// possible set sums are 3, 6, and 9. 
	// i.e. 1 + 2 + 3 = 6; 1 + 1 + 1 = 3; 2 + 2 + 2 = 6; 3 + 3 + 3 = 9;
	if ((c[0].getColor() + c[1].getColor() + c[2].getColor()) % 3 != 0 ||
		(c[0].getSymbol() + c[1].getSymbol() + c[2].getSymbol()) % 3 != 0 ||
		(c[0].getShading() + c[1].getShading() + c[2].getShading()) % 3 != 0 ||
		(c[0].getNumber() + c[1].getNumber() + c[2].getNumber()) % 3 != 0)
		return false;
	else return true;
}

/*
 *
 * I took a brute force approach to this, using some rough math first to know that I should start around 18-20,
 * After one day, I found a 19 card deal without a set, then continued on with 20
 * this random guesser with infinite loops took 5 days on a powerful computer to randomly find the 20 nonset deal
 * There was a 1 in 4,694,436,188,839,116,720 (I think) chance of this happening per iteration! (I got lucky on the random)
 * I ran it on 21, but by the deadline the 20 is all I found. I think that this is the true largest anyway
 
 * Here's the output of the 20 cards it found without a set:

A Purple Striped Oval with the number 1
A Green Striped Diamond with the number 2
A Green Solid Oval with the number 1
A Purple Open Squiggle with the number 3
A Purple Solid Squiggle with the number 2
A Purple Solid Oval with the number 1
A Purple Solid Squiggle with the number 1
A Green Striped Diamond with the number 1
A Purple Solid Oval with the number 2
A Green Open Diamond with the number 3
A Green Solid Oval with the number 2
A Green Striped Oval with the number 1
A Red Striped Diamond with the number 3
A Purple Striped Oval with the number 2
A Purple Striped Squiggle with the number 3
A Green Solid Diamond with the number 3
A Green Striped Oval with the number 2
A Green Solid Squiggle with the number 3
A Purple Striped Diamond with the number 3
A Red Solid Squiggle with the number 3

 * Average number of available sets at -
 * 12:  12!/(9!3!) * 1/79 = 2.78...
 * 18:  18!/(15!3!) * 1/79 = 10.33
 * 19:  19!/(16!3!) * 1/79 = 12.27
 * 20:  20!/(17!3!) * 1/79 = 14.43
 *
 */
void SetGame::findLargestNonSet()
{
	vector<Card> NoSetCards;
	vector<Card> testCards;
	Deck testDeck;

	int startNum = 19;
	for (int num = 0; num < 3; num++)
	{
		// this will run for a long time and has a small chance of succeeding!!!
		for (int i = 0; i < 10000; i++)
		// while (true)
		{
			testDeck.Shuffle();
			testDeck.Deal(startNum + num, testCards);
			if (findAllSets(testCards, false).size() == 0)
			{
				cout << "Found no sets in a deal of " << startNum + num << " cards. Continuing with " << startNum + num + 1 << endl;
				NoSetCards = testCards;
				break;
			}
			else if (i % 100 == 0)
			{
				cout << "Testing " << startNum + num << " the " << i << "th time" << endl;
			}
			else if (i == 9999)
			{
				cout << "Found sets in 10000 random deals of " << startNum + num << " cards" << endl;
				goto END;
			}
			testDeck.Replace(testCards);
		}
	}
END:
	printCards(NoSetCards);

	int x;
	cin >> x;
}