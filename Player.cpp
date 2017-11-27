/*
 * Player.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: lowji
 */

#include "Player.h"

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

void Player::setTotalChips(int chips){
	totalChips=chips;
}

void Player::setTempPool(int bet){
	tempBetPool=bet;
}

void Player::resetTempPool(){
	tempBetPool=0;
}

bool Player::raise(int prevBet, int newBet){
	if (newBet<=prevBet){
		return false;
	}
	else{
		setTempPool(newBet);
	}
	return true;
}

void Player::blind(int bet){
  tempBetPool = bet;
}

//EVERYTHING AFTER RAISE IS NOT DONE
