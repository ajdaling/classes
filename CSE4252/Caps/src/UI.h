/*
 * UI.h
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
 */

#ifndef UI_H_
#define UI_H_

namespace caps {

class UI {
public:
	UI();
	virtual ~UI();
	void welcome();
	void menu1();
	void addUser();
	void continueAsUser();
	void displayUsers();
	void startGame();
};

} /* namespace caps */

#endif /* UI_H_ */
