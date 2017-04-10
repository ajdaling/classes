/*
 * UI.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
 */

#include "UI.h"
#include "Game.h"
#include <iostream>
using namespace std;
namespace caps {

UI::UI() {
	// TODO Auto-generated constructor stub

}

UI::~UI() {
	// TODO Auto-generated destructor stub
}

void UI::welcome(){
	cout << "Hello" << endl;
	menu1();
}

void UI::menu1(){
	int response;
	cout << "Select an Option:" << endl;
	cout << "(1) - Add New User" << endl;
	cout << "(2) - Continue as Existing User" << endl;
	cout << "(3) - View Saved Users" << endl;
	cin >> response;
	switch(response){
	case 1:
		UI::addUser();
		break;
	case 2:
		continueAsUser();
		break;
	case 3:
		displayUsers();
		break;
	default:
		cout << "Invalid Response: Please Enter a valid number." << endl;
	}
}

void UI::addUser(){

}

void UI::continueAsUser(){
	cout << "Select a User: " << endl;
	cout << "(1) - test" << endl;
	UI::startGame();
}

void UI::displayUsers(){

}

void UI::startGame(){
	cout << "starting game" << endl;
}

} /* namespace caps */
