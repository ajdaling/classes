/*
 * UI.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
 */

#include "UI.h"
#include "User.h"
#include "Game.h"
#include "UserDB.h"
#include <iostream>
#include <map>
#include <utility>
#include <iterator>
using namespace std;
namespace caps {

UI::UI() {
	userDB = new UserDB();
	game = new Game();
}

UI::~UI() {
	// TODO Auto-generated destructor stub
}

void UI::welcome(){
	cout << "Hello" << endl;
	mainMenu();
}

void UI::mainMenu(){
	int response;
	cout << "Select an Option:" << endl;
	cout << "(1) - Add New User" << endl;
	cout << "(2) - Continue as Existing User" << endl;
	cout << "(3) - View Saved Users" << endl;
	cin >> response;
	cin.ignore();
	switch(response){
	case 1:
		addUser();
		break;
	case 2:
		continueAsUser();
		break;
	case 3:
		userDB->displayAllUsers();
		mainMenu();
		break;
	default:
		cout << "Invalid Response: Please Enter a valid number." << endl;
	}
}

void UI::addUser(){
	string username;
	cout << "Enter Username: ";
	getline(cin,username);
	cout << "Welcome. Your username is: " << username << endl;
	User* usr = new User(username);
	userDB->addUser(*usr);
	game->user = usr;
	game->startGame();
}

void UI::continueAsUser(){
	cout << "Saved users:" << endl;
	userDB->displayUserNames();
	string username;
	bool found = false;
	while(!found){
		cout << "Enter Username or enter \"main\" to return to main menu:";
		getline(cin,username);
		if(username.compare("main")==0){
			mainMenu();
		}
		else if(userDB->all_users.find(username) == userDB->all_users.end()){
			//username not in map
			cout << "Username not found. Try again or enter \"main\" to return to main menu." << endl;
		} else{
			//username found
			game->user = &(userDB->all_users[username]);
			game->startGame();
		}
	}



}

void UI::afterRoundMenu(int this_round_score){
	cout << "Nice job. You earned " << this_round_score << " this round. " << endl;
	cout << "Choose from the following options." << endl;
	cout << "(1) - Try again." << endl;
	cout << "(2) - Exit. " << endl;
	cout << "(3) - Return to main menu." << endl;
	int response;
}

} /* namespace caps */
