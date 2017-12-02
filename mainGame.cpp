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
#include "helper.h"

int main(){

	//set up user interface
  	ConsoleUI* ui = new ConsoleUI();

    ui->welcome();
	
	string inputTemp;
	inputTemp = ui->input("Input your name: ");
	Player* human = new Player(inputTemp);
	Player* AI = new Player("AI");

	helper* help=new helper();

	inputTemp=ui->input("How much do you want to buy-in? ");
	while(!help->isInt(inputTemp)){
		ui->output("Invalid input. Input must be an integer.");
		inputTemp=ui->input("How much do you want to buy-in? ");
	}
	human->setTotalChips(stoi(inputTemp));
	AI->setTotalChips(stoi(inputTemp));

	inputTemp=ui->input("How much do you want the small blind to be? ");
	while(!help->isInt(inputTemp)||stoi(inputTemp)>(human->getTotalChips()/10)){
		ui->output("Invalid input. Blind must be an integer that is less than 10% of your chips.");
		inputTemp=ui->input("How much do you want the small blind to be? ");
	}




	ui->output("Your name is "+human->getName());
	ui->output("Your opponent name is "+AI->getName());

	//shuffling(automatic shuffled)
    Deck* deck = new Deck();
	//draw cards
    human->addOne(deck->draw());
	human->addTwo(deck->draw());
	


	//print table: your stack, small blind, big blind, pot(needs to make)

    Board* bd = new Board(human,AI,0);
    bd->setBlind(stoi(inputTemp));
	while(human->getTotalChips() != 0 && AI->getTotalChips() != 0)
	{
		bd->preflop();
		bd->flop();
		bd->turn();
		bd->river();
		bd->clearBoard();
	}
	cout << "Game over. ";

}

