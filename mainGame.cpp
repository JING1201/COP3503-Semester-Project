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
#include "Board.h"
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
	while(!isInt(inputTemp)){
		ui->output("Invalid input. Blind must be an integer.");
		inputTemp=ui->input("How much do you want the blind to be? ");
	}

	//Preflop
	inputTemp=ui->input("How much do you want to buy-in? ");
	while(!isInt(inputTemp)){
		ui->output("Invalid input. Input must be an integer.");
		inputTemp=ui->input("How much do you want to buy-in? ");
	}
	human->setTotalChips(stoi(inputTemp));
	AI->setTotalChips(stoi(inputTemp));

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

    Board bd = Board(human,AI);
    bd.setBlind(stoi(inputTemp));
	while(human->getTotalChips() != 0 && AI->getTotalChips() != 0)
	{
		bd.preflop();
		bd.flop();
		bd.turn();
		bd.river();
		bd.clearBoard();
	}
	cout << "Game over. ";

}

