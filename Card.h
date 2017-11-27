
#ifndef Card_h
#define Card_h

using namespace std;

class Card
{
private:
	int number;
	int suit;
public:
	Card();
	Card(int number, int suit);
	void setNum(int number);
	void setSuit(int suit);
	int getNum();
	int getSuit();
	void printCard();
	void printNumber();
	void printSuit();

};
   

#endif // Card_h
