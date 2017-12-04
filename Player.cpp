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
void Player::decision(int pot){
	string inputTemp;
	helper* help=new helper();
	help->setStrengthChart();
	int strength=help->getStrength(&handOne,&handTwo);
	switch(strength){
	case 4:
		this->raise(2*pot);
		this->setPrevBet(2*pot);
		break;
	case 3:
		this->raise(pot*2/3);
		this->setPrevBet(pot*2/3);
		break;
	case 2:
		this->raise(pot/3);
		this->setPrevBet(pot/3);
		break;
	default:
		//this->call()
		break;
	}
}
