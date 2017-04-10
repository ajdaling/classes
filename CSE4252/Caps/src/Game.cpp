/*
 * Game.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
 */

#include "Game.h"
#include <fstream>
#include <assert.h>
#include <iostream>
using namespace std;
namespace caps {

Game::Game() {


}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::startGame(){
	cout << "loading data" << endl;
	loadCaps();
}

void Game::loadCaps(){
	ifstream in;
	string country;
	string capital;
	in.open("capitals.csv");
	assert(in.is_open());
	while(getline(in,country)){
		getline(in,capital);
		caps_map[country] = capital;
	}

}

} /* namespace caps */
