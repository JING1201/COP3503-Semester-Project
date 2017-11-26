#include "Hand.h"
#include "Deck.h"

#ifndef PLAYER_H_

#define PLAYER_H_

class Player{
 private:
  string name;
  int totalChips=0; 
  int tempBetPool=0; 
  Card handOne=0;
  Card handTwo=0; 
 public: 
 Player(string name): name(name){};
  void addOne(Card temp);
  void addTwo(Card temp);
  int getTotalChips();
  string getName();
  Card getHandOne();
  Card getHandTwo();
  int getTempPool();
  void setTotalChips();
  void setTemptPool(int bet);
  bool raise(int a, int b);
  void check();
  void fold();
  void blind();
  Deck finalHands();
  void gameOver();
};
#endif
