/*
 * UI.h
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
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

	UserDB* userDB;
	Game* game;
	void welcome();
	void mainMenu();
	void startGame();
	void addUser();
	void continueAsUser();
	void afterRoundMenu(int);
	void exitGame();
private:

};

} /* namespace caps */

#endif /* UI_H_ */
