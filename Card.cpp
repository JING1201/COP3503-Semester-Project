//******************************************************************************
//
// File Name:     Card.cpp
//
// File Overview: Represents a Card containing a number and a suit

#include <iostream>
#include "Card.h"
<<<<<<< HEAD
=======

>>>>>>> 3f3c22bcca68249cc632d7767565a44c4c0a1cea
using namespace std;
//******************************************************************************
// File scope (static) variable definitions
//******************************************************************************

// None

//******************************************************************************
// Function : constructor                                   
// Process  : Initialize data members to invalid values                    
// Notes    : Not the recommended constructor
//             Need to set the number and suit afterwards
//******************************************************************************                    
Card::Card()
{
   number=0;
   suit=0;
} // end Card::Card

//******************************************************************************
// Function : constructor                                   
// Process  : Initializes data members to input suit and number                    
// Notes    : Recommended constructor
//******************************************************************************                    
Card::Card(int number, int suit)
{
   this->number=number;
   this->suit=suit;
} // end Card::Card

void Card::setNumber(int number)
{
   this->number = number;
} // end Card::setNumber

//***************************************************************************
// Function : setSuit
// Process  : Mutator for suit
// Notes    : None
//***************************************************************************
void Card::setSuit(int suit)
{
   this->suit = suit;
} // end Card::setSuit

//***************************************************************************
// Function : getNumber
// Process  : Accessor for number
// Notes    : None
//***************************************************************************
int Card::getNumber()
{
   return this->number;
} // end Card::getNumber

//***************************************************************************
// Function : getSuit
// Process  : Accessor for suit
// Notes    : None
//***************************************************************************
int Card::getSuit()
{
   return this->suit;
} // end Card::getSuit

//***************************************************************************
// Function : printCard                                   
// Process  : Print the card number and suit
//             Call printNumber
//             Call printSuit
// Notes    : None
//***************************************************************************
void Card::printCard()
{
   this->printNumber();
   this->printSuit();
} // end Card::printCard

//***************************************************************************
// Function : printNumber                                   
// Process  : print the card number
//             11 - J for Jack
//             12 - Q for Queen
//             13 - K for King
//             14 - A for Ace
// Notes    : None
//***************************************************************************
void Card::printNumber()
{
   int number = this->getNumber(); // Obtain the card's number

   if (number > 1 && number < 11)
   	  {
         cout << number;
      }
   	  else if (number == 11)
      {
         cout << "J";
      }
   	  else if (number == 12)
      {
         cout << "Q";
      }
   	  else if (number == 13)
      {
         cout << "K";
      }
   	  else if (number == 14)
      {
         cout << "A";
      }
   	  else
   	  {
   	     cout << " Invalid number ";
   	  }
} // end Card::printNumber


//***************************************************************************
// Function : printSuit                                   
// Process  : Print the card suit
// Notes    : None
//***************************************************************************
void Card::printSuit()
{
	int suit = this->getSuit(); // Obtain the card's suit
   
	if(suit == 0)
	{
	 cout << "s" << " ";
	}
	else if(suit == 1)
	{
	 cout << "h" << " ";
	}
	else if(suit == 2)
	{
	 cout << "d" << " ";
	}
	else if(suit == 3)
	{
	 cout << "c" << " ";
	}
	else
	{
	 cout << "Invalid suit" << " ";
	}
	cout<<endl;
} // end Card::printSuit

      
