//******************************************************************************
//
// Revision History:
//
// Date           Author               Description
// 11/27/2017     Jason Chen           Added class
//******************************************************************************

#include <iostream>
#include "Deck.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Card.h"
using namespace std;

//constructor
//initialize a new deck with a shuffle
Deck::Deck()
{
	shuffle();
}

//load 52 cards into the array deck
//using locations from 0 to 51
//0-12 corresponds to suit 0
//13-25 corresponds to suit 1
//26-38 corresponds to suit 2
//39-51 corresponds to suit 3
void Deck::shuffle()
{
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			deck[i + 13 * j] = Card(i + 2, j);
		}
	}
}

Card Deck::draw()
{
	srand((unsigned) time(NULL));

	while(true)
	{
		int k = rand() % 52;
		if(deck[k].getNumber() != 0)
		{
			Card temp = deck[k];
			std::cout << " random number is " << k << " " << endl;
			deck[k] = Card(0, 0);
			std::cout << " Card temp number is " << temp.getNumber() << " " << endl;
			return temp;
		}
	}
	return Card();
}

Card Deck::getCard(int num, int suit)
{
	return deck[num + 13 * suit];
}

