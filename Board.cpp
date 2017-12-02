//******************************************************************************
// Board.cpp
// Revision History:
//
// Date           Author               Description
// 11/28/2017     Jason Chen           Added class
//******************************************************************************

#include <iostream>
#include <sstream>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "Board.h"
#include "Player.h"
#include "ConsoleUI.h"
#include "helper.h"
using namespace std;


//constructor
//initialize the board for a new game
Board::Board(Player* hum, Player* AI, int smallBlindPlayer)
{
	human = hum;
	this->AI=AI;
	setCommunity();
	help=new helper();
	this->smallBlindPlayer=smallBlindPlayer;
}

void Board::setBlind(int bld)
{
	smallBlind = bld;
}

void Board::setCommunity()
{
	for(int i = 0; i < 5; i++)
	{
		community[i] = dek.draw();
	}
}

void Board::printBoard()
{
	cout << "The pot is: " << pot << endl;
	cout << "Your stack size is: " << human->getTotalChips() << endl;
	cout << "AI's stack size is: " << "Print AI's stack size" << endl << endl;
}

bool Board::preflop()
{
	printBoard();
	ConsoleUI* ui=new ConsoleUI();
	string inputTemp;
	//print user's hand
	ui->output("Your hand: ");
	(human->getHandOne()).printCard();
	(human->getHandTwo()).printCard();
	//force user to put in blind


	while(human->getTempPool()!=AI->getTempPool()) //player facing a bet
	{
		if (smallBlindPlayer==1){
			//AI goes first
			AI->decision(); //
		}
		else if (smallBlindPlayer==0){
			//player goes first
		}
		/*inputTemp=ui->input("Fold (1), Check (2), or Raise (3)\n");
		while (!help->isInt(inputTemp)||stoi(inputTemp)<1||stoi(inputTemp)>3){
			ui->output("Input must be an integer.");
			inputTemp=ui->input("Fold (1), Check (2), or Raise (3)");
		}
		//switch cases depending on user's choice
		int choice=stoi(inputTemp);
		switch(choice){
		case 1:
			//end the round, goto another round of preflop
			break;
		case 2:
			human->setTempPool(blind);
			//anything else to do
			break;
		case 3:
			break;
		}*/
	}

	//update pot
	//update player's stack
	//update AI's stack
	printBoard();
	return false;
}

bool Board::flop()
{
	printBoard();
	cout << "The flop is " << endl;
	community[0].printCard();
	community[1].printCard();
	community[2].printCard();
	cout << endl << "Your hand: " << "Print Player One's hand" <<endl;
	if(true) //player facing a bet
	{
		cout << "Fold, Check, or Bet" << endl;
		//user input
	}
	else //player not facing a bet
	{
		cout << "Check or Bet" << endl;
		//user input
	}
	//update pot
	//update player's stack
	printBoard();

	return false;
}

bool Board::turn()
{
	printBoard();
	cout << "The turn is " << endl;
	community[0].printCard();
	community[1].printCard();
	community[2].printCard();
	community[3].printCard();
	cout << endl << "Your hand: " << "Print Player One's hand" <<endl;
	if(true) //player facing a bet
	{
		cout << "Fold, Check, or Bet" << endl;
		//user input
	}
	else //player not facing a bet
	{
		cout << "Check or Bet" << endl;
		//user input
	}
	//update pot
	//update player's stack
	printBoard();

	return false;
}

bool Board::river()
{
	printBoard();
	cout << "The flop is " << endl;
	community[0].printCard();
	community[1].printCard();
	community[2].printCard();
	community[3].printCard();
	community[4].printCard();
	cout << endl << "Your hand: " << "Print Player One's hand" <<endl;
	if(true) //player facing a bet
	{
		cout << "Fold, Check, or Bet" << endl;
		//user input
	}
	else //player not facing a bret
	{
		cout << "Check or Bet" << endl;
		//user input
	}
	//update pot
	//update player's stack
	printBoard();
	return false;
}

void Board::clearBoard()
{
	dek.shuffle();
	setCommunity();
	if (smallBlindPlayer==0){
		smallBlindPlayer=1;
	}
	else{
		smallBlindPlayer=0;
	}
}
