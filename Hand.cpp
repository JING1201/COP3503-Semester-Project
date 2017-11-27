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
// 11/27/2017     Jason Chen           Added Class
//******************************************************************************

#include <iostream>
#include "Hand.h"
#include <algorithm>


Hand::Hand(Card card0, Card card1, Card card2, Card card3, Card card4)
{
	first  = card0;
	second = card1;
	third  = card2;
	fourth = card3;
	fifth  = card4;

	type = this->getType();
	suit = this->getSuit();
	quad = this->getQuad();
	trip = this->getTrip();
	doub = this->getDoub();
	conn = this->getConn();
	high = this->getHigh();
}

//***************************************************************************
// Function : getQuad
// Process  : checks if the hand is suited
//            return 1 for suited, return 0 for non-suited
// Notes    : None
//***************************************************************************
int Hand::getSuit()
{
    int suits[] = {first.getSuit(), second.getSuit(), third.getSuit(), fourth.getSuit(), fifth.getSuit()};
    vector<int> vsuits (suits, suits+5);
    sort(vsuits.begin(),vsuits.begin()+5);
    vector<int>::iterator it;
    it = std::unique(vsuits.begin(), vsuits.end());
    vsuits.resize(std::distance(vsuits.begin(), it));
    if(vsuits.size() == 1)
    {
    	return 1;
    }
    else
    {
    	return 0;
    }
}

//***************************************************************************
// Function : getQuad
// Process  : checks for quads
//            return a positive number in base 100 with the most significant bit representing the quadrupled value
//            the least significant bit represents kicker's value
//            return 0 if no quadruplet is detected
// Notes    : The kicker here is optional, notice that comparing quads can be simplified by invoking the high card method
//***************************************************************************
int Hand::getQuad()
{
    int numbers[] = {first.getNumber(), second.getNumber(), third.getNumber(), fourth.getNumber(), fifth.getNumber()};
    vector<int> vnumbers (numbers, numbers+5);
    sort(vnumbers.begin(),vnumbers.begin()+5);
    int count = 1, temp = 1, quad = 0, kicker = 0;
    for(unsigned int i = 0; i < vnumbers.size() - 1; i++)
    {
        if(vnumbers[i] == vnumbers[i + 1])
        {
        	if(temp == 1)
        	{
        		count++;
        		quad = 100 * vnumbers[i];
        	}
        	else
        	{
        		temp = 1;
        		count = 2;
        	}
        }
        else
        {
        	if(i == 0)
        	{
        		kicker = vnumbers[0];
        	}
        	if(i == 3)
        	{
        		kicker = vnumbers[4];
        	}
        	temp = 0;
        }
    }
    if(count == 4)
    {
    	return quad + kicker;
    }
    else
    {
    	return 0;
    }
}

//***************************************************************************
// Function : getDoub
// Process  : checks for the any three of a kind or full house in a hand
//            return a positive number in base 100 with the most significant bit representing the pair value
//            the least significant bit represents the triplet's value
//            return 0 if no triplet is detected
// Notes    : None
//***************************************************************************
int Hand::getTrip()
{
	int numbers[] = {first.getNumber(), second.getNumber(), third.getNumber(), fourth.getNumber(), fifth.getNumber()};
	vector<int> vnumbers (numbers, numbers+5);
	sort(vnumbers.begin(),vnumbers.begin()+5);
	int maxcount = 0, count = 1, temp = 1, triple = 0, full = 0;
	for(unsigned int i = 0; i < vnumbers.size() - 1; i++)
	{
		if(vnumbers[i] == vnumbers[i + 1])
		{
			if(temp == 1)
			{
				count++;
				maxcount = count;
				triple = vnumbers[i];
			}
			else
			{
				temp = 1;
				count = 2;
			}
		}
		else
		{
			//AABBB
			if(i == 1)
			{
				if(vnumbers[0] == vnumbers[1])
				{
					full = vnumbers[0] * 100;
				}
			}
			//AAABB
			if(i == 2)
			{
				if(vnumbers[3] == vnumbers[4])
				{
					full = vnumbers[3] * 100;
				}
			}
			temp = 0;
		}
	}
	if(maxcount == 3)
	{
		return full + triple;
	}
	else
	{
		return 0;
	}
}

//***************************************************************************
// Function : getDoub
// Process  : checks for the any pairs in a hand
//            return a positive number for two pairs or one pair
//            return 0 for non-paired
// Notes    : None
//***************************************************************************
int Hand::getDoub()
{
	int numbers[] = {first.getNumber(), second.getNumber(), third.getNumber(), fourth.getNumber(), fifth.getNumber()};
	vector<int> vnumbers (numbers, numbers+5);
	sort(vnumbers.begin(),vnumbers.begin()+5);
	int count = 1, doub1 = 0, doub2 = 0;
	for(unsigned int i = 0; i < vnumbers.size() - 1; i++)
	{
		if(vnumbers[i] == vnumbers[i + 1])
		{
			if(count == 1)
			{
				count++;
				doub2 = vnumbers[i];
			}
			else
			{
				doub1 = vnumbers[i] * 100;
			}
		}
	}
	return doub1 + doub2;
}

//***************************************************************************
// Function : getConn
// Process  : checks the connectivity of a hand
//            return the largest number within a straight
//            return 0 for non-straight
// Notes    : None
//***************************************************************************
int Hand::getConn()
{
	int numbers[] = {first.getNumber(), second.getNumber(), third.getNumber(), fourth.getNumber(), fifth.getNumber()};
	vector<int> vnumbers (numbers, numbers+5);
	sort(vnumbers.begin(),vnumbers.begin()+5);
	int straight = 0;
	for(unsigned int i = 0; i < vnumbers.size() - 1; i++)
	{
		if(vnumbers[i] + 1 == vnumbers[i + 1])
		{
			straight = vnumbers[i + 1];
		}
		else
		{
			return 0;
		}
	}
	return straight;
}

//***************************************************************************
// Function : getHigh
// Process  : return a base 100, encoded 10 digits number
//				representing the high card value of a hand
// Notes    : None
//***************************************************************************
int Hand::getHigh()
{
	int numbers[] = {first.getNumber(), second.getNumber(), third.getNumber(), fourth.getNumber(), fifth.getNumber()};
	vector<int> vnumbers (numbers, numbers+5);
	sort(vnumbers.begin(),vnumbers.begin()+5);
    return vnumbers[4] * 100000000 + vnumbers[3] * 1000000 + vnumbers[2] * 10000 + vnumbers[1] * 100 + vnumbers[0];
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

//***************************************************************************
// Function : getType
// Process  : return values corresponds to the type of hand from 0 to 8
// Notes    : None
//***************************************************************************
int Hand::getType()
{
	if(suit == 1 && conn > 1)
		return 8;
	else if(quad > 0)
		return 7;
	else if(trip > 100)
		return 6;
	else if(suit == 1)
		return 5;
	else if(conn > 0)
		return 4;
	else if(trip > 0)
		return 3;
	else if(doub > 100)
		return 2;
	else if(doub > 0)
		return 1;
	else
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
