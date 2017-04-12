/*
 * UI.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
 */

#include "UI.h"
#include "Game.h"
#include "UserDB.h"
#include <stdlib.h>
#include <string>
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
	cout << "Select an Option:" << endl;
	cout << "(1) - Add New User" << endl;
	cout << "(2) - Continue as Existing User" << endl;
	cout << "(3) - View Saved Users" << endl;
	cout << "(4) - Exit" << endl;
	string s_response;
	int response;
	bool error = true;
	//cout << "Enter a new value: "; // I don't like doing this.
	while(error == true)
	{
		cout << "Enter a number: " << flush;
		getline(cin,s_response);
		for(unsigned int i = 0; i<s_response.length(); i++){
			if(isalpha(s_response[i])){
				error = true;
			} else {
				error = false;
			}
		}
		if(error == true){
			cout << "Invalid response." << endl;
		}
	}
	response = atoi(s_response.c_str());
	switch(response){
	case 1:
		addUser();
		startGame();
		break;
	case 2:
		continueAsUser();
		startGame();
		break;
	case 3:
		userDB->displayAllUsers();
		mainMenu();
		break;
	case 4:
		exitGame();
		break;
	default:
		cout << "Invalid Response: Please Enter a valid number." << endl;
		mainMenu();
	}
}

void UI::addUser(){
	string username;
	cout << "Enter Username (no spaces): ";
	getline(cin,username);
	cout << "Welcome. Your username is: " << username << endl;
	game->setUser(userDB->addUser(username));
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
			found = true;
			mainMenu();
		} else {
			if(userDB->hasUser(username)){
				found = true;
				game->setUser(userDB->getUser(username));
			} else{
				cout << "Username not found.";
			}
		}
	}
}

void UI::startGame(){
	int round_score = game->startGame();
	afterRoundMenu(round_score);
}

void UI::afterRoundMenu(int this_round_score){
	//offer to save score
	cout << "Good Job. You earned " << this_round_score << " points. Save score? (y/n):";
	string save_score;
	getline(cin,save_score);
	if(save_score.compare("y")==0){
		cout << "saving score." << endl;
		userDB->saveUserScore(game->getUserName(),this_round_score);
	} else {
		cout << "Score not saved." << endl;
	}


	cout << "Choose from the following options." << endl;
	cout << "(1) - Try again." << endl;
	cout << "(2) - Exit. " << endl;
	cout << "(3) - Return to main menu." << endl;

	string s_response;
	int response;
	bool error = true;
	//cout << "Enter a new value: "; // I don't like doing this.
	while(error == true)
	{
		cout << "Enter a number: " << flush;
		getline(cin,s_response);
		for(unsigned int i = 0; i<s_response.length(); i++){
			if(isalpha(s_response[i])){
				error = true;
				break;
			} else {
				error = false;
			}
		}
		response = atoi(s_response.c_str());
		if(response < 1 || response > 3){
			error = true;
		}
		if(error == true){
			cout << "Invalid response." << endl;
		}
	}


	switch(response){
	case 1:
		startGame();
		break;
	case 2:
		exitGame();
		break;
	case 3:
		mainMenu();
		break;
	default:
		cout << "Invalid input. Please enter a valid number." << endl;
		break;
	}
}

void UI::exitGame(){
	cout << "Writing data to file.";
	userDB->writeUserData();
}
} /* namespace caps */
