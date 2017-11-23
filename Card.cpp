/*
 * Card.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: lowji
 */

#include <iostream>
using namespace std;
#include "Card.h"

Card::Card(string suitIn, string rankIn){
	suit=suitIn;
	rank=rankIn;
}

string Card::getSuit(){
	return suit;
}

string Card::getRank(){
	return rank;
}


