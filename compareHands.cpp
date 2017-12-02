/*
 * compareHands.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: swli
 */
#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"

//returns 2 when they tie, 1 when hand1 wins, and 0 when hand 2 wins
int compareHands(Hand* hand1, Hand* hand2)
{
	int i = 2;
	if(hand1->getType() > hand2->getType())
	{
		i = 1;
	}
	else if(hand1->getType() < hand2->getType())
	{
		i = 0;
	}
	else
	{

		if(hand1->getType() == 1 || hand1->getType() == 2)
		{
			if(hand1 -> getDoub() > hand2 -> getDoub())
			{
				i = 1;
			}
			else if(hand1 -> getDoub() < hand2 -> getDoub())
			{
				i = 0;
			}
		}
		else if(hand1 -> getType() == 6 || hand1 -> getType() == 3)
		{
			if((hand1 -> getTrip())%100 > (hand2 -> getTrip())%100)
			{
				i = 1;
			}
			else if((hand1 -> getTrip())%100 < (hand2 -> getTrip())%100)
			{
				i = 0;
			}
		}
		else if (hand1 -> getType() == 7)
		{
			if(hand1 -> getQuad() > hand2 -> getQuad())
			{
				i = 1;
			}
			else if(hand1->getQuad() < hand2->getQuad())
			{
				i = 0;
			}
		}
		if(i == 2)
		{
			if(hand1 -> getHigh() > hand2 -> getHigh())
			{
				i = 1;
			}
			else if(hand1->getHigh() < hand2->getHigh())
			{
				i = 0;
			}
		}
	}
	return i;
}

//returns the highest value hand from a pool of 7 cards
Hand* bestHand(Card card0, Card card1, Card card2, Card card3, Card card4, Card card5, Card card6)
{
	Hand* best = new Hand(card0,card1,card2,card3,card4);
	Hand* comp;
	int ori1;
	int ori2;
	for(int i = 0; i < 6; i++)
	{
		for(int j = i + 1; j < 7; j++)
		{
			vector<Card> temp;
			ori1 = i;
			ori2 = j;
			if(ori1 != 0 && ori2 != 0)
			{
				temp.push_back(card0);
			}
			if(ori1 != 1 && ori2 != 1)
			{
				temp.push_back(card1);
			}
			if(ori1 != 2 && ori2 != 2)
			{
				temp.push_back(card2);
			}
			if(ori1 != 3 && ori2 != 3)
			{
				temp.push_back(card3);
			}
			if(ori1 != 4 && ori2 != 4)
			{
				temp.push_back(card4);
			}
			if(ori1 != 5 && ori2 != 5)
			{
				temp.push_back(card5);
			}
			if(ori1 != 6 && ori2 != 6)
			{
				temp.push_back(card6);
			}
			comp = new Hand(temp[0],temp[1],temp[2],temp[3],temp[4]);
			if(compareHands(comp,best) == 1)
			{
				best = comp;
			}
		}
	}
	return best;
}
