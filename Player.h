#include "Deck.h"
#include <iostream>
#include "Card.h"
#ifndef PLAYER_H_

#define PLAYER_H_

class Player{
 private:
  string name;
  int totalChips=0;
  int tempBetPool=0;
  int prevBet = 0;
  Card handOne;
  Card handTwo;
 public:
  Player(string name);
  void addOne(Card temp);
  void addTwo(Card temp);
  int getTotalChips();
  string getName();
  Card getHandOne();
  Card getHandTwo();
  int getTempPool();
  int getPrevBet();
  void setPrevBet(int num);
  void setTotalChips(int chips);
  void setTempPool(int bet);
  void resetTempPool();
  void raise(int newBet);
  void check();
  void fold();
  void blind(int bet);
  Deck finalHands();
  void gameOver();
  void call(Player* opp);
  bool decision(int pot, int sb, int phase, Player * hum, Card Card2, Card Card3, Card Card4, Card Card5, Card Card6);
};
#endif
