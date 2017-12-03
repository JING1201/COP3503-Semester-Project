/*
 * helper.h
 *
 *  Created on: Dec 2, 2017
 *      Author: lowji
 */

#ifndef HELPER_H_
#define HELPER_H_
#include <iostream>
#include "Card.h"
#include "Hand.h"

namespace std {

class helper {
private:
	int strengthChart[13][13];
public:
	helper();
	bool isInt(string input);
	int getStrength(Card* card1, Card* card2);
	void setStrengthChart();
	int compareHands(Hand* hand1, Hand* hand2);
	Hand* bestHand(Card card0, Card card1, Card card2, Card card3, Card card4, Card card5, Card card6);
};

} /* namespace std */

#endif /* HELPER_H_ */
