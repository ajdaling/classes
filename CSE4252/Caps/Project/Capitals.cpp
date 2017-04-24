/*
 * Capitals.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: Alec Daling
 *	
 *	Contains the main function for the caps game. Creates a UI object and calls
 *	UI.welcome() which starts the user interface for the game.
 */
#include <vector>
#include "UI.h"

#include <iostream>
using namespace std;
using namespace caps;
int main(){
	UI* ui =  new UI();
	ui->welcome();
	return 0;
}


