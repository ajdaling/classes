/*
 * Game.h
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
 */

#ifndef GAME_H_
#define GAME_H_
#include "User.h"
#include <vector>
#include <map>
#include <string>

namespace caps {

class Game {
public:
	Game();
	virtual ~Game();
	void startGame();
	map<string,string> caps_map;

private:
	void loadCaps();

};


} /* namespace caps */

#endif /* GAME_H_ */
