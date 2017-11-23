/*
 * Card.h
 *
 *  Created on: Oct 31, 2017
 *      Author: lowji
 */

#ifndef CARD_H_
#define CARD_H_
#include <iostream>
using namespace std;

class Card {
private:
	string rank;
	string suit;
public:
	Card(string suitIn, string rankIn);
	string getSuit();
	string getRank();
};


#endif /* CARD_H_ */
