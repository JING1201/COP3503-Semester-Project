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

class Board
{
	private:
		Player human;
	    Deck dek = Deck();
		Card community[5];
		int blind;
		int pot;
	public:
		Board(Player hum);
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
