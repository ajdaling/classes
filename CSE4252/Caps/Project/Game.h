/*
 * Game.h
 *
 *  Created on: Apr 10, 2017
 *      Author: Alec Daling
 
 
 		Game class - controls process flow for running a round of the caps game. Contains
 		a User object passed by UI.
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
	int startGame();
	void setUser(User* usr);
	string getUserName();
	std::vector< std::pair <std::string,std::string> > caps_vec;

private:

	void loadCaps(); //loads question data from csv file
	void beginRound(); //begins round of questions
	int roundHandler(); //controls process flow for rounds
	pair<string,string> questionHandler(); //randomly selects and returns pair<country,capital> for question
	int answerHandler(pair<string,string>, bool*); //decides what to do with input
	User* user; //user object assigned to game.
};


} /* namespace caps */

#endif /* GAME_H_ */
