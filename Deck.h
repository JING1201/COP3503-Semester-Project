//******************************************************************************
//
// Revision History:
//
// Date           Author               Description
// 11/27/2017     Jason Chen           Added class
//******************************************************************************
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
