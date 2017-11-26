//******************************************************************************
//
// File Name:     Card.h
//
// File Overview: Represents a Card containing a number and a suit

//******************************************************************************

#ifndef Card_h
#define Card_h

using namespace std;

//******************************************************************************
//
// Class:    Card
//
// Notes    : None
//
//******************************************************************************
class Card
{
private:
	int number;
	int suit;
public:
	Card();
	Card(int number, int suit);
	void setNumber(int number);
	void setSuit(int suit);
	int getNumber();
	int getSuit();
	void printCard();
	void printNumber();
	void printSuit();

}; // end class Card
   

#endif // Card_h
