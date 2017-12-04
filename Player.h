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
  void blind(int bet);
  void call(Player* opp);
  void decision(int pot, int sb, Player * hum);
};
#endif
