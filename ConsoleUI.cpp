/*
 * UI.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: lowji
 */

#include "ConsoleUI.h"


ConsoleUI::ConsoleUI() {
	return;
}

void ConsoleUI::welcome(){
	cout<<"Welcome to the Poker Game!\n";
	//can modify later for fancier display
}

string ConsoleUI::input(string request){
	cout<<request;
	string temp;
	cin>>temp;
	return temp;
}

void ConsoleUI::output(string content){
	cout<<content<<endl;
}



