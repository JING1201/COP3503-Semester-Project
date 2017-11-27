//******************************************************************************
//
// File Name:     Hand.cpp
//
// File Overview: Represents a Hand containing five cards
//
//******************************************************************************
//
// Revision History:
//
// Date           Author               Description 
// 11/25/2017        Jason Chen         Added class
//******************************************************************************

#include <iostream>
#include "Hand.h"
#include <algorithm>


Hand::Hand(Card * card0, Card * card1, Card * card2, Card * card3, Card * card4)
{
	type = this->getType();
	first  = *card0;
	second = *card1;
	third  = *card2;
	fourth = *card3;
	fifth  = *card4;
}


//***************************************************************************
// Function : printHand                                   
// Process  : Print the hand by calling each card's print method
//             Print the hand type
// Notes    : None
//***************************************************************************
void Hand::printHand()
{
   Card card;  // Current card, used to iterate the hand and print each card
   first.printCard();
   second.printCard();
   third.printCard();
   fourth.printCard();
   fifth.printCard();

   this->printType();
}

int Hand::getType()
{
	return 0;
}

//***************************************************************************
// Function : printType                                   
// Process  : Print the hand type  (straight flush, full house, etc)  
// Notes    : None
//***************************************************************************
void Hand::printType()
{
   int type = this->getType();

      if( type == 0)
      {
         cout << "(High Card)";
      }
      else if( type == 1)
      {
         cout << "(Pair)";
      }
      else if( type == 2)
      {
         cout << "(Two Pair)";
      }
      else if( type == 3)
      {
         cout << "(Three of a Kind)";
      }
      else if( type == 4)
      {
         cout << "(Straight)";
      }
      else if( type == 5)
      {
         cout << "(Flush)";
      }
      else if( type == 6)
      {
         cout << "(Full House)";
      }
      else if( type == 7)
      {
         cout << "(Four of a Kind)";
      }
      else if( type == 8)
      {
         cout << "(Straight Flush)";
      }
      else
      {
    	  cout << "(Invalid Type)";
      }
}
