/*
 * mainGame.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: lowji
 */

//created this source file to make the compiler work properly
#include <sstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "ConsoleUI.h"
#include "Card.h"
#include "Deck.h"
//method to determine if a string is an integer
bool isInt(string input){
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

int main(){

	//set up user interface
  	ConsoleUI* ui = new ConsoleUI();

       	ui->welcome();
	
	string inputTemp;
	inputTemp = ui->input("Input your name: ");
	Player* human = new Player(inputTemp);
	Player* AI = new Player("AI");
	
	//Preflop
	
	inputTemp=ui->input("How much do you want the blind to be? ");
	//const int BLIND=inputTemp;
	ui->output("Your name is "+human->getName());
	ui->output("Your opponent name is "+AI->getName());

	//shuffling(automatic shuffled)
       	Deck* deck = new Deck();
	//draw cards
    human->addOne(deck->draw());
	human->addTwo(deck->draw());
	
	//print user's hand
	ui->output("Print "+ human->getName()+"'s hand");
       	(human->getHandOne()).printCard();
       	(human->getHandTwo()).printCard();
	//print table: your stack, small blind, big blind, pot(needs to make)

	//prompt user decision: raise, bet, check=bet(0), fold


	//Postflop: prompt user, update pot and each player stack size(money), user's decision, draw 3 cards into communitycards, print pot and stacksize, print hands, print communitycards

	//Turn:  prompt user, update pot and each player stack size(money), user's decision, draw 1 cards into communitycards, print pot and stacksize, print hands, print communitycards

	//River: repeat Turn, and go back to preflop...
}

