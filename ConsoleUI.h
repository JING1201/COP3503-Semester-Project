/*
 * UI.h
 *
 *  Created on: Nov 27, 2017
 *      Author: lowji
 */

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
