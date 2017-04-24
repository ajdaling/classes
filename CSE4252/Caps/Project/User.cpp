/*
 * User.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: Alec Daling
 */

#include "User.h"
#include <iostream>

using namespace std;
namespace caps{

//default constructor - creates empty User object
User::User(){
	high_score = 0;
	user_name = "";
}
// overloaded constructor - creates new User object with name only
User::User(string username){
	high_score = 0;
	user_name = username;
}
//overloaded constructor used by UserDB - creates new User object with score history
User::User(string name, vector<int> score_hist) {
	user_name = name;
	score_history = score_hist;
	high_score = 0;
	for(unsigned int i = 0; i < score_history.size(); i++){
		if(score_history[i] > high_score){
			high_score = score_history[i];
		}
	}
}

User::~User() {
	// TODO Auto-generated destructor stub
}

string User::getName(){
	return(user_name);
}

//adds score to User's score history
void User::saveScore(int round_score){
	cout << "saving score in User.cpp" << endl;
	cout << "score is: " << round_score << endl;
	score_history.push_back(round_score);
	updateHighScore();
}

//checks if new score is higher than user's high score. If so, updates high score.
void User::updateHighScore(){
	int hs = 0;
	for(unsigned int i = 0; i < score_history.size(); i++){
		if(score_history[i] > hs){
			hs = score_history[i];
		}
	}
	high_score = hs;
}

//writes user's name, high score, and score history to console.
void User::displayUserInfo(){
	cout << user_name << "||  High Score: " << high_score;
	cout << " || Score History:";
	for(unsigned int i = 0; i < score_history.size(); i++){
		cout << " " << score_history[i] << ",";
	}
	cout << endl;
}
// displays user name
void User::displayUserName(){
	cout << user_name << endl;
}
}
