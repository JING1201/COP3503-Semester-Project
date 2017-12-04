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
void Player::decision(int pot, int sb, Player * hum){
	string inputTemp;
	helper* help=new helper();
	ConsoleUI* ui = new ConsoleUI();
	help->setStrengthChart();
	int strength=help->getStrength(&handOne,&handTwo);
	switch(strength){
	case 4:
		this->raise(pot);
		this->setPrevBet(pot);
		ui->output("Case 4: AI raised $" + to_string(pot));
		break;
	case 3:
		this->raise(pot*2/3/sb*sb);
		this->setPrevBet(pot*2/3/sb*sb);
		ui->output("Case 3: AI raised $"+to_string(pot*2/3/sb*sb));
		break;
	case 2:
		this->raise(pot/3/sb*sb);
		this->setPrevBet(pot/3/sb*sb);
		ui->output("Case 2: AI raised $"+to_string(pot/3/sb*sb));
		break;
	case 1:
		this->call(hum);
		ui->output("Case 1: AI called.");
		break;
	case 0:
		this->call(hum);
		ui->output("Case 0: AI called.");
		break;
	}
}
