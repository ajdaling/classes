/*
 * User.h
 *
 *  Created on: Apr 10, 2017
 *      Author: Alec Daling
 */

#ifndef USER_H_
#define USER_H_
#include <vector>
#include <string>
using namespace std;


namespace caps{
class User{
public:
	User();
	User(string username);
	User(string name, vector<int> score_history);
	virtual ~User();
	string getName(); //returns string containing user's name
	void displayUserInfo(); //writes user info to console (name, high score, score history)
	void displayUserName(); //write user name to console
	void saveScore(int); //adds score (int) to user's score history
	vector<int> score_history; //vector of ints containing user's past scores.


private:
	string user_name; //username
	int high_score; 
	void updateHighScore(); //iterates through score history and updates high score.

};


}

#endif /* USER_H_ */


