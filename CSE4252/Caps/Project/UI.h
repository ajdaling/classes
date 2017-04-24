/*
 * UI.h
 *
 *  Created on: Apr 10, 2017
 *      Author: Alec Daling
 */

#ifndef UI_H_
#define UI_H_
#include "UserDB.h"
#include "Game.h"
#include "User.h"
namespace caps {

class UI {
public:
	UI();
	virtual ~UI();

	UserDB* userDB; //UserDB object
	Game* game; //Game object
	void welcome(); //says hello and starts main menu
	void mainMenu(); //lists main options, (create user, select user, view saved users, exit)
	void startGame(); //starts game
	void addUser(); //creates new user and adds to UserDB
	void continueAsUser(); //selects user from UserDB
	void afterRoundMenu(int); //offers to try again, exit, or return to main menu
	void exitGame(); //exits
private:

};

} /* namespace caps */

#endif /* UI_H_ */
