//******************************************************************************
// Board.h
// Revision History:
//
// Date           Author               Description
// 11/28/2017     Jason Chen           Added class
//******************************************************************************

#ifndef BOARD_H_
#define BOARD_H_
#include "Card.h"
#include "Player.h"
#include "helper.h"

class Board
{
	private:
		Player* human;
		Player* AI;
	    Deck dek = Deck();
		Card community[5];
		int blind=0;
		int pot=0;
		helper* help;

	public:
		Board(Player* hum, Player* AI);
		void setCommunity();
		void setBlind(int bld);
		void printStack();
		void preflop();
		void flop();
		void turn();
		void river();
		void printBoard();
		void clearBoard();
};



#endif /* BOARD_H_ */
