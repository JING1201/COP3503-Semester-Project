/*
 * mainGame.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: lowji
 */

//created this source file to make the compiler work properly

#include <iostream>
#include <string>
#include "Player.cpp"//Player.cpp already includes Player.h 
int main(){
  cout<<"Input your name:"<<endl;
  string input;
  cin>>input;
  string name = input;
  Player* human = new Player(input);
  Player* AI = new Player("AI");
  //Preflop
 cout<<"How much do you want the blind to be?"<<endl; 
  cin>>input;
  human->setTotalChips(stoi(input));
  AI->setTotalChips(stoi(input));
  cout<<"Your name is "<<human->getName()<<endl;
  cout<<"Your opponent name is "<<AI->getName()<<endl;
  cout<<"your blind is "<<human->getTotalChips()<<endl;
  cout<<"Ai has blind of "<<AI->getTotalChips()<<endl;
  //shuffling
  
  //draw cards

  //print user's hand

  //print table: your pocket, small blind, big blind, pot(needs to make) 

  //prompt user decision: raise, bet, check, fold


  //Postflop: prompt user, update pot and each player stack size(money), user's decision, draw 3 cards into communitycards, print pot and stacksize, print hands, print communitycards 

  //Turn:  prompt user, update pot and each player stack size(money), user's decision, draw 1 cards into communitycards, print pot and stacksize, print hands, print communitycards 

  //River: repeat Turn, and go back to preflop...


}

