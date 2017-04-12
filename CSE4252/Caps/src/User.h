/*
 * User.h
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
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
	string getName();
	void displayUserInfo();
	void displayUserName();
	void saveScore(int);
	vector<int> score_history;


private:
	string user_name;
	int high_score;
	void updateHighScore();

};


}

#endif /* USER_H_ */


