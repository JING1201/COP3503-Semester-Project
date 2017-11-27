/*
 * Deck.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: lowji
 */

#include "Deck.h"
#include <stack>
#include "Card.h"
using namespace std;

Deck::Deck(){
	deck=new stack<Card>();
}

void Deck::add(Card newCard){
	deck->push(newCard);
}

Card Deck::withdraw(){
	Card temp=deck->top();
	deck->pop();
	return temp;
}

stack<Card> Deck::getDeck(){
	return *deck;
}


