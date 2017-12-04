//******************************************************************************
//
// File Name:     helper.cpp
//
// File Overview: A class that contains helper methods that do not belong to
//			any conceptual class in the project

#include "helper.h"
#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include <sstream>
using namespace std;

//******************************************************************************
// Function : constructor                                   
// Process  : Initialize data members                     
// Notes    : None
//            
//****************************************************************************** 

helper::helper() {
	// TODO Auto-generated constructor stub
	for (int i=0;i<13;i++){
		for (int j=0;j<13;j++){
			strengthChart[i][i]=0;
		}
	}
}

//******************************************************************************
// Function : isInt                                  
// Process  : Determines if a string input is an integer
// Notes    : None
//******************************************************************************

bool helper::isInt(string input){
	//Reference: https://stackoverflow.com/questions/20287186/how-to-check-if-the-input-is-a-valid-integer-without-any-other-chars

	int x; //temporary int variable for checking input validity
	char c; //temporary char variable for checking input validity
	istringstream s(input);

	if (!(s >> x)) {
		return false;
	}

	if (s >> c) {
		return false;
	}

	return true;
}

//******************************************************************************
// Function : getStrength                                   
// Process  : Returns an integer representing the "strength" of the stronger 
//		card
// Notes    : This is done using a predetermined "strength chart"
//******************************************************************************

int helper::getStrength(Card* card1, Card* card2){
	int num1=card1->getNumber();
	int num2=card2->getNumber();
	if (card1->getSuit()==card2->getSuit()){
		return strengthChart[14-max(num1,num2)][14-min(num1,num2)];
	}
	else{
		return strengthChart[14-min(num1,num2)][14-max(num1,num2)];
	}
}

//******************************************************************************
// Function : setStrengthChart()                                   
// Process  : Creates a "strength chart" according to standard poker rules.
// Notes    : None
//******************************************************************************

void helper::setStrengthChart(){
	//https://howtoplaypokerinfo.com/wp-content/uploads/2016/06/Poker-cheat-sheet-card-printout-400x210.png

	//setting strength 4
	for (int i=0;i<13;i++){
		strengthChart[i][i]=4;
	}
	for (int i=0;i<4;i++){
		for (int j=0;j<5;j++){
			strengthChart[i][j]=4;
		}
	}
	//setting strength 3
	strengthChart[4][0]=3;
	strengthChart[3][1]=3;
	strengthChart[3][2]=3;
	strengthChart[1][4]=3;
	strengthChart[2][4]=3;
	strengthChart[3][4]=3;
	strengthChart[4][5]=3;
	//setting strength 2
	for (int i=5;i<13;i++){
		strengthChart[0][i]=2;
	}
	for (int i=1;i<4;i++){
		strengthChart[i][5]=2;
	}
	for (int i=1;i<4;i++){
		strengthChart[4][i]=2;
	}
	strengthChart[5][0]=2;
	strengthChart[6][0]=2;
	strengthChart[5][6]=2;
	strengthChart[6][7]=2;
	//setting strength 1
	for (int i=1;i<5;i++){
		strengthChart[i][6]=1;
	}
	strengthChart[1][7]=1;
	strengthChart[5][7]=1;
	strengthChart[6][8]=1;
	strengthChart[7][9]=1;
	strengthChart[7][8]=1;
	strengthChart[8][9]=1;
	strengthChart[9][10]=1;
	for (int i=7;i<13;i++){
		strengthChart[i][0]=1;
	}
	for (int i=5;i<8;i++){
		strengthChart[i][1]=1;
	}
	for (int i=2;i<5;i++){
		strengthChart[5][i]=1;
	}

	//print to test
	/*for (int i=0;i<13;i++){
		for (int j=0;j<13;j++){
			cout<<strengthChart[i][j]<<"\t";
		}
		cout<<endl;
	}*/
}

//******************************************************************************
// Function : compareHands                                   
// Process  : Compares 2 hands of cards and returns an integer according to who
//		wins or draws.
// Notes    : This is done according to standard poker rules.
//******************************************************************************

//returns 2 when they tie, 1 when hand1 wins, and 0 when hand 2 wins
int helper::compareHands(Hand* hand1, Hand* hand2)
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

//******************************************************************************
// Function : bestHand                                   
// Process  : Returns a pointer to the best possible hand given a set of 7 cards
// Notes    : The function iterates through all 7C2 = 21 possibilities.
//******************************************************************************

//returns the highest value hand from a pool of 7 cards
Hand* helper::bestHand(Card card0, Card card1, Card card2, Card card3, Card card4, Card card5, Card card6)
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
			if(this->compareHands(comp,best) == 1)
			{
				best = comp;
			}
		}
	}
	return best;
}



 /* namespace std */

/*int main(){
	helper* help=new helper();
	help->setStrengthChart();
	Card* one=new Card(12,1);
	Card* two=new Card(11,2);
	cout<<help->getStrength(one,two);
}*/

