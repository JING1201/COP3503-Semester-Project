//******************************************************************************
//
// File Name:     Deck.h
//
// File Overview: Header file of Deck.cpp
//			Represents a deck of 52 cards

#ifndef DECK_H_
#define DECK_H_
#include "Card.h"
#include <stack>
using namespace std;

class Deck
{
	private:
		Card deck[52];
	public:
		Deck();
		void shuffle();
		Card getCard(int num, int suit);
		Card draw();
};



#endif /* DECK_H_ */
