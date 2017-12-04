//******************************************************************************
//
// File Name:     ConsoleUI.h
//
// File Overview: Header file of ConsoleUI.cpp 

#ifndef CONSOLEUI_H_
#define CONSOLEUI_H_

#include <iostream>
using namespace std;

class ConsoleUI {
	public:
		ConsoleUI();
		void welcome();
		string input(string request);
		void output(string content);
};



#endif /* CONSOLEUI_H_ */
