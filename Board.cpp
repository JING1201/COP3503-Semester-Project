//******************************************************************************
// Board.cpp
// Revision History:
//
// Date           Author               Description
// 11/28/2017     Jason Chen           Added class
//******************************************************************************

#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "Board.h"
#include "Player.h"
#include "ConsoleUI.h"
using namespace std;

//constructor
//initialize the board for a new game
Board::Board(Player hum, Player Ai)
{
	human = hum;
	AI = Ai;
	setCommunity();
}

void Board::setBlind(int bld)
{
	blind = bld;
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
	ConsoleUI* ui=new ConsoleUI();
	ui->output("The pot is: "+pot);
	ui->output("Your stack size is: "+human.getTotalChips());
	ui->output("AI's stack size is: "+"Print AI's stack size");
}

void Board::preflop()
{
	printBoard();
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
	//update AI's stack
	printBoard();
}

void Board::flop()
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

}

void Board::clearBoard()
{
	dek.shuffle();
	setCommunity();
}
