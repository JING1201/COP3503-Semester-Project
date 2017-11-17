/*
 * Deck.h
 *
 *  Created on: Nov 16, 2017
 *      Author: lowji
 */

#ifndef DECK_H_
#define DECK_H_
#include "Card.h"
#include <vector>
using namespace std;

class Deck{
	private:
		vector<Card>* deck;
	public:
		Deck(){
			deck=new vector<Card>();
		}
		void add(Card newCard);
		Card withdraw();
		vector<Card> getDeck();
		Card getCard(int index);
};

void Deck::add(Card newCard){

}



#endif /* DECK_H_ */
