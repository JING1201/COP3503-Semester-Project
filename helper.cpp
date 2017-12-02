/*
 * helper.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: lowji
 */

#include "helper.h"
#include <sstream>
using namespace std;

namespace std {

helper::helper() {
	// TODO Auto-generated constructor stub
	for (int i=0;i<13;i++){
		for (int j=0;j<13;j++){
			strengthChart[i][i]=0;
		}
	}
}

//method to determine if a string is an integer
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

} /* namespace std */

/*int main(){
	helper* help=new helper();
	help->setStrengthChart();
	Card* one=new Card(12,1);
	Card* two=new Card(11,2);
	cout<<help->getStrength(one,two);
}*/

