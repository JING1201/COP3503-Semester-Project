/*
 * Player.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: lowji
 */

#include "Player.h"
#include "Card.h"
#include "helper.h"
#include "Board.h"
#include "ConsoleUI.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
Player::Player(string name){
	this->name=name;
}

void Player::addOne(Card temp){
	handOne=temp;
}

void Player::addTwo(Card temp){
	handTwo=temp;
}

int Player::getTotalChips(){
	return totalChips;
}

string Player::getName(){
	return name;
}

Card Player::getHandOne(){
	return handOne;
}

Card Player::getHandTwo(){
	return handTwo;
}

int Player::getTempPool(){
	return tempBetPool;
}
int Player::getPrevBet()
{
	return prevBet;
}
void Player::setPrevBet(int num)
{
	prevBet = num;
}
void Player::setTotalChips(int chips){
	totalChips=chips;
}

void Player::setTempPool(int bet){
	tempBetPool=bet;
}

void Player::resetTempPool(){
	tempBetPool=0;
}

void Player::raise(int newBet){
	setTempPool(tempBetPool + newBet);
	setTotalChips(totalChips-newBet);
}

void Player::blind(int bet){
  tempBetPool = bet;
}

void Player::call(Player* opp){
	int change = opp->getTempPool()-tempBetPool;
	tempBetPool = opp->getTempPool();
	setTotalChips(totalChips-change);
}

//only for AI
void Player::decision(int pot, int sb, int phase, Player * hum){
	string inputTemp;
	ConsoleUI* ui = new ConsoleUI();
	helper* help=new helper();
	help->setStrengthChart();
	int strength=help->getStrength(&handOne,&handTwo);
	srand((unsigned) time(NULL));
	switch(strength){
	case 4:
	{
		int temp = (pot * (200 + rand() % 100) / 250 + sb / 2) / sb * sb;
		this->raise(temp);
		this->setPrevBet(temp);
		ui->output("AI raised $" + to_string(temp));
		break;
	}
	case 3:
	{
		int temp2 = (pot * (200 + rand() % 100) / 250 * 2 / 3 + sb / 2) / sb * sb;
		this->setPrevBet(temp2);
		ui->output("AI raised $" + to_string(temp2));
		break;
	}
	case 2:
	{
		int temp3 = (pot * (200 + rand() % 100) / 250 / 3 + sb / 2) / sb * sb;
		this->raise(temp3);
		this->setPrevBet(temp3);
		ui->output("AI raised $" + to_string(temp3));
		break;
	}
	case 1:
	{
		int temp4 = ((pot * (200 + rand() % 100) / 250 / 3 + sb / 2) / sb * sb);
		this->raise(temp4);
		this->setPrevBet(temp4);
		ui->output("AI raised $" + to_string(temp4));
		break;
	}
	case 0:
	{
		this->call(hum);
		ui->output("AI Called.");
		break;
	}
	}
}

