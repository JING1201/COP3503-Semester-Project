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

	inputTemp=ui->input("How much do you want to buy-in?");
	while(!help->isInt(inputTemp)||stoi(inputTemp)<20){
		ui->output("Invalid input. Input must be an integer equal or larger than 20");
		inputTemp=ui->input("How much do you want to buy-in?");
	}
	human->setTotalChips(stoi(inputTemp));
	AI->setTotalChips(stoi(inputTemp));

	inputTemp=ui->input("How much do you want the small blind to be?");
	while(!help->isInt(inputTemp)||stoi(inputTemp)>(human->getTotalChips()/20)){
		ui->output("Invalid input.\nBlind must be an integer that is less than or equal to 5% of your chips.");
		inputTemp=ui->input("How much do you want the small blind to be?");
	}

	ui->output("");
	ui->output("Your name is "+human->getName());
	ui->output("Your opponent name is "+AI->getName());
	ui->output("");


	//print table: your stack, small blind, big blind, pot(needs to make)
	ui->output("================GAME BEGINS================\n");
    Board* bd = new Board(human,AI,0);
    bd->setBlind(stoi(inputTemp));
    bool foldFlag;
    int countRound=0;
	while(human->getTotalChips() > 0 && AI->getTotalChips() > 0)
	{
		countRound++;
		ui->output("---------------ROUND "+to_string(countRound)+" BEGIN------------\n");
		foldFlag=false;
		//bd->clearBoard();
		ui->output("------------Begin Pre-flop---------------\n");
		foldFlag=bd->preflop(); //returns true if folded
		if (foldFlag){
			//there's probably an easier way to do this
			bd->clearBoard();
			bd->printBoard();
			inputTemp=ui->input("Do you want to continue?(Y/N) ");
			while(inputTemp != "Y" && inputTemp != "N" && inputTemp != "y" && inputTemp != "n"){
				ui->output("Please select Y or N");
				inputTemp=ui->input("Do you want to continue?(Y/N) ");
			}
			if(inputTemp == "N" || inputTemp == "n")
			{
				break;
			}
			continue;
		}
		ui->output("------------Begin Flop---------------\n");
		foldFlag=bd->flop();
		if (foldFlag){
			bd->clearBoard();
			bd->printBoard();
			inputTemp=ui->input("Do you want to continue?(Y/N) ");
			while(inputTemp != "Y" && inputTemp != "N" && inputTemp != "y" && inputTemp != "n"){
				ui->output("Please select Y or N");
				inputTemp=ui->input("Do you want to continue?(Y/N) ");
			}
			if(inputTemp == "N" || inputTemp == "n")
			{
				break;
			}
			continue;
		}
		ui->output("--------------Begin Turn---------------\n");
		foldFlag=bd->turn();
		if (foldFlag){
			bd->clearBoard();
			bd->printBoard();
			inputTemp=ui->input("Do you want to continue?(Y/N) ");
			while(inputTemp != "Y" && inputTemp != "N" && inputTemp != "y" && inputTemp != "n"){
				ui->output("Please select Y or N");
				inputTemp=ui->input("Do you want to continue?(Y/N) ");
			}
			if(inputTemp == "N" || inputTemp == "n")
			{
				break;
			}
			continue;
		}
		ui->output("--------------Begin River---------------\n");
		foldFlag=bd->river();
		if (foldFlag){
			bd->clearBoard();
			bd->printBoard();
			inputTemp=ui->input("Do you want to continue?(Y/N) ");
			while(inputTemp != "Y" && inputTemp != "N" && inputTemp != "y" && inputTemp != "n"){
				ui->output("Please select Y or N");
				inputTemp=ui->input("Do you want to continue?(Y/N) ");
			}
			if(inputTemp == "N" || inputTemp == "n")
			{
				break;
			}
			continue;
		}
		bd->clearBoard();
		bd->printBoard();
		inputTemp=ui->input("Do you want to continue?(Y/N) ");
		while(inputTemp != "Y" && inputTemp != "N" && inputTemp != "y" && inputTemp != "n"){
			ui->output("Please select Y or N");
			inputTemp=ui->input("Do you want to continue?(Y/N) ");
		}
		if(inputTemp == "N" || inputTemp == "n")
		{
			break;
		}
		ui->output("-----------------END OF ROUND "+to_string(countRound)+"---------------\n");
	}
	ui->output("You have played "+to_string(countRound)+" round(s).");
	if(human->getTotalChips() > AI->getTotalChips()){
		ui->output("Congratulations you have won $"+ to_string((human->getTotalChips() - AI->getTotalChips()) / 2)+"from our AI.");
	}
	else if(human->getTotalChips() <= 0)
		ui->output("Unfortunately, you have lost all of your chips. Better luck next time!");
	else
		ui->output("You left the game with $"+to_string(human->getTotalChips())+ ".");

}
