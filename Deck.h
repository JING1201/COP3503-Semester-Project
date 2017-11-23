/*
 * Deck.h
 *
 *  Created on: Nov 16, 2017
 *      Author: lowji
 */

#ifndef DECK_H_
#define DECK_H_
#include "Card.h"
#include <stack>
using namespace std;

class Deck{
	private:
		stack<Card>* deck;
	public:
		Deck();
		void add(Card newCard);
		Card withdraw();
		stack<Card> getDeck();
};





#endif /* DECK_H_ */
