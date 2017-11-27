#include "Deck.h"
#include <iostream>

#ifndef PLAYER_H_

#define PLAYER_H_

class Player{
 private:
  string name;
  int totalChips=0; 
  int tempBetPool=0; 
  Card handOne;
  Card handTwo;
 public: 
 Player(string name): name(name){};
  void addOne(Card temp);
  void addTwo(Card temp);
  int getTotalChips();
  string getName();
  Card getHandOne();
  Card getHandTwo();
  int getTempPool();
  void setTotalChips(int chips);
  void setTempPool(int bet);
  void resetTempPool();
  bool raise(int prevBet, int newBet);
  void check();
  void fold();
  void blind(int bet);
  Deck finalHands();
  void gameOver();
};
#endif
