/*
 * Game.h
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
 */

#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include <iostream>
#include <utility>
#include "User.h"

#include <map>
#include <string>

namespace caps {
using namespace std;
class Game {

public:
	Game();
	static const int MAX_SCORE = 5; //max points (and attempts) per question
	static const int MAX_TIME = 1; // max time per round
	virtual ~Game();
	void startGame();
	std::vector< std::pair <std::string,std::string> > caps_vec;
	User* user;

private:

	void loadCaps(); //loads question data from csv file
	void beginRound();
	void roundHandler(); //
	pair<string,string> questionHandler(); //randomly selects and returns pair<country,capital> for question
	int answerHandler(pair<string,string>, bool*); //decides what to do with input
};


} /* namespace caps */

#endif /* GAME_H_ */
