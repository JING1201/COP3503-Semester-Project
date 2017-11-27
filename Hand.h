//******************************************************************************
//
// File Name:     Hand.h
//
// File Overview: Represents a Hand containing five cards
//******************************************************************************

#ifndef Hand_h
#define Hand_h

#include <algorithm>
#include <map>
#include <vector>
#include "Card.h"

//******************************************************************************
//
// Class:    Hand
//
// Notes    : None
//
//******************************************************************************
class Hand
{
public:
	int type;
	int suit;
	int quad;
	int trip;
	int doub;
	int conn;
	int high;

	Card first;
	Card second;
	Card third;
	Card fourth;
	Card fifth;

	Hand(Card card0, Card card1, Card card2, Card card3, Card card4);
	int getSuit();
	int getQuad();
	int getTrip();
	int getDoub();
	int getConn();
	int getHigh();
	void printType();
	void printHand();
	int getType();
};

#endif // Hand_h
