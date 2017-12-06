//******************************************************************************
// Board.cpp
// Revision History:
//
// Date           Author               Description
// 11/28/2017     Jason Chen           Added class
//******************************************************************************

#include <iostream>
#include <sstream>
#include <string>
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

void Board::resetPot(){
	pot=0;
}

void Board::setCommunity()
{
	for(int i = 0; i < 5; i++)
	{
		community[i] = dek.draw();
	}
	//set player cards
	human->addOne(dek.draw());
	human->addTwo(dek.draw());
	AI->addOne(dek.draw());
	AI->addTwo(dek.draw());
}

void Board::printBoard()
{
	ConsoleUI* ui=new ConsoleUI();
	ui->output("*************************************");
	ui->output("");
	ui->output(AI->getName()+":\t$"+to_string(AI->getTotalChips()));
	ui->output("\t$"+to_string(AI->getTempPool()));
	ui->output("");
	ui->output("Pot:\t$"+to_string(pot));
	ui->output("");
	ui->output("\t$"+to_string(human->getTempPool()));
	ui->output(human->getName()+":\t$"+to_string(human->getTotalChips()));
	ui->output("");
	ui->output("*************************************\n");
}

bool Board::run()
{
	printBoard();
	string inputTemp;
	ConsoleUI* ui = new ConsoleUI();
	ui->output("Your turn: \n");
	if(human ->getTotalChips() < AI->getPrevBet())
	{
		inputTemp = ui->input("Fold (1) or All in (4)");
		while (!help->isInt(inputTemp)||(stoi(inputTemp)!=1 && stoi(inputTemp)!=4))
		{
			ui->output("Input must a choice number provided");
			inputTemp=ui->input("Fold (1) or All in (4)");
		}
	}
	else if(human->getTotalChips() < 2*AI->getPrevBet())
	{
		inputTemp=ui->input("Fold (1), Call (2), or All in (4)\n");
		while (!help->isInt(inputTemp)||(stoi(inputTemp)!=1 && stoi(inputTemp)!=3 &&stoi(inputTemp)!=4))
		{
			ui->output("Input must a choice number provided");
			inputTemp=ui->input("Fold (1), Call (2), or All in (4)");
		}
	}
	else if(human->getTempPool() < AI->getTempPool())
	{
		inputTemp=ui->input("Fold (1), Call (2), or Raise (3)\n");
		while (!help->isInt(inputTemp)||stoi(inputTemp)<1||stoi(inputTemp)>3)
		{
			ui->output("Input must a choice number provided");
			inputTemp=ui->input("Fold (1), Call (2), or Raise (3)");
		}
	}
	else
	{
		inputTemp=ui->input("Fold (1), Check (2), or Raise (3)\n");
		while (!help->isInt(inputTemp)||stoi(inputTemp)<1||stoi(inputTemp)>3)
		{
			ui->output("Input must be a choice number provided.");
			inputTemp=ui->input("Fold (1), Check (2), or Raise (3)");
		}
	}
	if(inputTemp == "1")
	{
		return true;
	}
	else if(inputTemp == "2")
	{
		human->call(AI);
		pot=human->getTempPool()+AI->getTempPool();
		printBoard();
		return false;
	}
	else if(inputTemp == "3")
	{
		int prev = AI->getPrevBet();
		string r = ui->input("How much do you want to raise by? ");
		while (!help->isInt(r)|| stoi(r) < prev*2 || stoi(r) > min(human->getTotalChips() + human->getTempPool(), AI->getTotalChips() + AI->getTempPool()) || stoi(r) % smallBlind != 0)
		{
			if(!help->isInt(r))
				ui->output("Input must be an integer.");
			else if(stoi(r) < prev*2)
				ui->output("Input must be at least double the previous bet.");
			else if(stoi(r) > min(human->getTotalChips() + human->getTempPool(), AI->getTotalChips() + AI->getTempPool()))
				ui->output("Input must be less than or equal to the effective chip amount.");
			else
				ui->output("Input must be a multiple of the small blind.");
			r=ui->input("How much do you want to raise by? ");
		}
		human->raise(stoi(r));
		pot=human->getTempPool()+AI->getTempPool();
		human->setPrevBet(stoi(r));
		printBoard();
		return false;
	}
	else
	{
		human->raise(human->getTotalChips());
		pot=human->getTempPool()+AI->getTempPool();
		if(human ->getTotalChips() < AI->getPrevBet())
		{
			result();
			pot = 0;
			return true;
		}
		printBoard();
		return false;
	}

}

bool Board::runAI(int phase){
	ConsoleUI* ui = new ConsoleUI();
	ui->output("AI's turn: ");
	bool foldFlag = AI->decision(pot, smallBlind, phase, human, community[0], community[1], community[2], community[3], community[4]); //for now
	pot=AI->getTempPool()+human->getTempPool();
	//return true if fold
	return foldFlag;
}
bool Board::preflop()
{
	human->setPrevBet(0);
	AI->setPrevBet(0);
	printBoard();
	ConsoleUI* ui=new ConsoleUI();
	string inputTemp;
	//print AI's hand
	ui->output("AI's hand: ");
	(AI->getHandOne()).printCard();
	(AI->getHandTwo()).printCard();
	ui->output("");
	//print user's hand
	ui->output("Your hand: ");
	(human->getHandOne()).printCard();
	(human->getHandTwo()).printCard();
	ui->output("");
	//force user to put in blind
	pot=smallBlind*3;
	if (smallBlindPlayer==0){
		AI->raise(smallBlind);
		human->raise(smallBlind*2);
		ui->output("AI paid the small blind: "+to_string(smallBlind));
		ui->output("You paid the big blind: "+to_string(smallBlind*2));
	}
	else{
		smallBlindPlayer=0;
		human->raise(smallBlind);
		AI->raise(smallBlind*2);
		ui->output("You paid the small blind: "+to_string(smallBlind));
		ui->output("AI paid the big blind: "+to_string(smallBlind*2));
	}
	ui->output("");
	//ui->output("Your total chips: "+to_string(human->getTotalChips()));
	//ui->output("AI's total chips: "+to_string(AI->getTotalChips()));

	//cout<<"small blind player : "<<smallBlindPlayer<<endl;
	int first = 0;
	int i;
	while(human->getTempPool()!=AI->getTempPool()) //player facing a bet
	{
		if (smallBlindPlayer==1){
			//AI goes first
			i = human->getTempPool()-AI->getTempPool();
			bool flag=this->runAI(1);
			if (flag==true){
				human->setTotalChips(human->getTotalChips()+pot);
				return true;
			}
			if(i > 0 && human->getTempPool()==AI->getTempPool() && first != 0)
			{
				break;
			}
			flag=this->run();
			if (flag==true){
				AI->setTotalChips(AI->getTotalChips()+pot);
				return true;
			}
		}
		else if (smallBlindPlayer==0){
			//player goes first
			i = AI->getTempPool()-human->getTempPool();
			bool flag=this->run();
			if (flag==true){
				AI->setTotalChips(AI->getTotalChips()+pot);
				return true;
			}
			if(i > 0 && human->getTempPool()==AI->getTempPool() && first != 0)
			{
				break;
			}
			flag=this->runAI(1);
			if (flag==true){
				human->setTotalChips(human->getTotalChips()+pot);
				return true;
			}
		}
		first++;
	}
	return false;
}

bool Board::flop()
{
	human->setPrevBet(0);
	AI->setPrevBet(0);
	if(AI->getTotalChips() == 0 || human->getTotalChips() == 0)
	{
		result();
		return true;
	}
	ConsoleUI* ui=new ConsoleUI();
	cout << "The flop is " << endl;
	community[0].printCard();
	community[1].printCard();
	community[2].printCard();
	cout << endl;
	//print AI's hand
	ui->output("AI's hand: ");
	(AI->getHandOne()).printCard();
	(AI->getHandTwo()).printCard();
	ui->output("");
	//print user's hand
	ui->output("Your hand: ");
	(human->getHandOne()).printCard();
	(human->getHandTwo()).printCard();
	ui->output("");
	//cout<<"small blind player : "<<smallBlindPlayer<<endl;
	int i;
	do
	{
		if (smallBlindPlayer==1){
			//AI goes first
			i = human->getTempPool()-AI->getTempPool();
			bool flag=this->runAI(2);
			if (flag==true){
				human->setTotalChips(human->getTotalChips()+pot);
				return true;
			}
			flag=this->run();
			if(i > 0 && human->getTempPool()== AI->getTempPool())
			{
				break;
			}
			if (flag==true){
				AI->setTotalChips(AI->getTotalChips()+pot);
				return true;
			}
		}
		else if (smallBlindPlayer==0){
			//player goes first
			i = AI->getTempPool()-human->getTempPool();
			bool flag=this->run();
			if(i > 0 && human->getTempPool() == AI->getTempPool())
			{
				break;
			}
			if (flag==true){
				AI->setTotalChips(AI->getTotalChips()+pot);
				return true;
			}
			flag=this->runAI(2);
			if (flag==true){
				human->setTotalChips(human->getTotalChips()+pot);
				return true;
			}
		}
	}
	while(human->getTempPool()!=AI->getTempPool()); //player facing a bet

	return false;
}

bool Board::turn()
{
	human->setPrevBet(0);
	AI->setPrevBet(0);
	if(AI->getTotalChips() == 0 || human->getTotalChips() == 0)
	{
		result();
		return true;
	}
	cout << "The turn is " << endl;
	community[0].printCard();
	community[1].printCard();
	community[2].printCard();
	community[3].printCard();
	cout << endl;
	ConsoleUI* ui=new ConsoleUI();
	//print AI's hand
	ui->output("AI's hand: ");
	(AI->getHandOne()).printCard();
	(AI->getHandTwo()).printCard();
	ui->output("");
	//print user's hand
	ui->output("Your hand: ");
	(human->getHandOne()).printCard();
	(human->getHandTwo()).printCard();
	ui->output("");
	ui->output("");
	ui->output("Your total chips: "+to_string(human->getTotalChips()));
	ui->output("AI's total chips: "+to_string(AI->getTotalChips()));
	int i;
	do
	{
		if (smallBlindPlayer==1){
			//AI goes first
			i = human->getTempPool()-AI->getTempPool();
			bool flag=this->runAI(3);
			if (flag==true){
				human->setTotalChips(human->getTotalChips()+pot);
				return true;
			}
			flag=this->run();
			if(i > 0 && human->getTempPool()== AI->getTempPool())
			{
				break;
			}
			if (flag==true){
				AI->setTotalChips(AI->getTotalChips()+pot);
				return true;
			}
		}
		else if (smallBlindPlayer==0){
			//player goes first
			i = AI->getTempPool()-human->getTempPool();
			bool flag=this->run();
			if(i > 0 && human->getTempPool() == AI->getTempPool())
			{
				break;
			}
			if (flag==true){
				AI->setTotalChips(AI->getTotalChips()+pot);
				return true;
			}
			flag=this->runAI(3);
			if (flag==true){
				human->setTotalChips(human->getTotalChips()+pot);
				return true;
			}
		}
	}
	while(human->getTempPool()!=AI->getTempPool()); //player facing a bet
	return false;
}

bool Board::river()
{
	human->setPrevBet(0);
	AI->setPrevBet(0);
	if(AI->getTotalChips() == 0 || human->getTotalChips() == 0)
	{
		result();
		return true;
	}
	cout << "The river is " << endl;
	community[0].printCard();
	community[1].printCard();
	community[2].printCard();
	community[3].printCard();
	community[4].printCard();
	cout << endl;
	ConsoleUI* ui=new ConsoleUI();
	//print AI's hand
	ui->output("AI's hand: ");
	(AI->getHandOne()).printCard();
	(AI->getHandTwo()).printCard();
	ui->output("");
	//print user's hand
	ui->output("Your hand: ");
	(human->getHandOne()).printCard();
	(human->getHandTwo()).printCard();
	ui->output("");
	//ui->output("");
	//ui->output("Your total chips: "+to_string(human->getTotalChips()));
	//ui->output("AI's total chips: "+to_string(AI->getTotalChips()));
	int i;
	do
	{
		if (smallBlindPlayer==1){
			//AI goes first
			i = human->getTempPool()-AI->getTempPool();
			this->runAI(4);
			bool flag=this->run();
			if(i > 0 && human->getTempPool()== AI->getTempPool())
			{
				break;
			}
			if (flag==true){
				AI->setTotalChips(AI->getTotalChips()+pot);
				return true;
			}
		}
		else if (smallBlindPlayer==0){
			//player goes first
			i = AI->getTempPool()-human->getTempPool();
			bool flag=this->run();
			if(i > 0 && human->getTempPool() == AI->getTempPool())
			{
				break;
			}
			if (flag==true){
				AI->setTotalChips(AI->getTotalChips()+pot);
				return true;
			}
			this->runAI(4);
		}
	}
	while(human->getTempPool()!=AI->getTempPool()); //player facing a bet
	result();
	return false;
	//after everything is done
}
void Board::result()
{
	ConsoleUI* ui=new ConsoleUI();
	ui->output("----------RESULTS----------");
	Hand* humanBest=help->bestHand((human->getHandOne()),(human->getHandTwo()),
					community[0],community[1],community[2],community[3],community[4]);
	Hand* AIBest=help->bestHand((AI->getHandOne()),(AI->getHandTwo()),
			community[0],community[1],community[2],community[3],community[4]);
	int result=help->compareHands(humanBest,AIBest);
	ui->output("Community Cards: ");
	for (int i=0;i<5;i++){
		community[i].printCard();
	}
	ui->output("");
	ui->output("AI's cards: ");
	AI->getHandOne().printCard();
	AI->getHandTwo().printCard();
	ui->output("");
	ui->output("Your cards: ");
	human->getHandOne().printCard();
	human->getHandTwo().printCard();
	ui->output("");
	ui->output("Your best hand: ");
	humanBest->printHand();
	ui->output("");
	ui->output("AI's best hand: ");
	AIBest->printHand();
	ui->output("");
	if (result==1){
		ui->output("You won.\n");
		human->setTotalChips(human->getTotalChips()+pot);
	}
	else if (result==0){
		ui->output("AI won. \n");
		AI->setTotalChips(AI->getTotalChips()+pot);
	}
	else{
		ui->output("Tie. \n");
		human->setTotalChips(human->getTotalChips()+pot/2);
		AI->setTotalChips(AI->getTotalChips()+pot/2);
	}
}

void Board::clearBoard()
{
	human->resetTempPool();
	AI->resetTempPool();
	pot=0;
	human->setPrevBet(0);
	AI->setPrevBet(0);
	dek.shuffle();
	setCommunity();
	if (smallBlindPlayer==0){
		smallBlindPlayer=1;
	}
	else{
		smallBlindPlayer=0;
	}
}
