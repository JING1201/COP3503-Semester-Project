//******************************************************************************
//
// File Name:     ConsoleUI.cpp
//
// File Overview: Controls the input and output of the poker game.	

#include "ConsoleUI.h"

//******************************************************************************
// Function : constructor                                   
// Process  : None                    
// Notes    : None             
//******************************************************************************    

ConsoleUI::ConsoleUI() {
	return;
}

//******************************************************************************
// Function : welcome                                   
// Process  : Outputs a welcome statement to the poker game.
// Notes    : None
//******************************************************************************    

void ConsoleUI::welcome(){
	cout<<"Welcome to the Poker Game!\n";
	//can modify later for fancier display
}

//******************************************************************************
// Function : input                                   
// Process  : Outputs a string and returns a string.                
// Notes    : None
//******************************************************************************    

string ConsoleUI::input(string request){
	cout<<request;
	string temp;
	cin>>temp;
	return temp;
}

//******************************************************************************
// Function : constructor                                   
// Process  : Outputs a string.
// Notes    : None
//******************************************************************************    

void ConsoleUI::output(string content){
	cout<<content<<endl;
}




