#include <iostream>
#include "Card.h"


Card::Card()
{
   number=0;
   suit=0;
}

Card::Card(int number, int suit)
{
   this->number=number;
   this->suit=suit;
}

void Card::setNum(int number)
{
   this->number = number;
}

void Card::setSuit(int suit)
{
   this->suit = suit;
}

int Card::getNum()
{
   return this->number;
}

int Card::getSuit()
{
   return this->suit;
}

void Card::printCard()
{
   this->printNumber();
   this->printSuit();
}

void Card::printNumber()
{
   int number = this->getNum();

   if (number > 1 && number < 11)
   	  {
         cout << number;
      }
   	  else if (number == 11) //jack
      {
         cout << "J";
      }
   	  else if (number == 12) //queen
      {
         cout << "Q";
      }
   	  else if (number == 13) //king
      {
         cout << "K";
      }
   	  else if (number == 14) //ace
      {
         cout << "A";
      }
   	  else
   	  {
   	     cout << "Invalid number";
   	  }
}

void Card::printSuit()
{
	int suit = this->getSuit();
   
	if(suit == 1)
	{
	 cout << "s" << " ";
	}
	else if(suit == 2)
	{
	 cout << "h" << " ";
	}
	else if(suit == 3)
	{
	 cout << "d" << " ";
	}
	else if(suit == 4)
	{
	 cout << "c" << " ";
	}
	else
	{
	 cout << "Invalid suit" << " ";
	}
}

      
