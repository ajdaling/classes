/*
 * UserDB.h
 *
 *  Created on: Apr 10, 2017
 *      Author: Alec Daling
 */

#ifndef USERDB_H_
#define USERDB_H_
#include "User.h"
#include <map>
namespace caps{

using namespace std;

class UserDB {
public:
	UserDB();
	virtual ~UserDB();
	User* getUser(string username); //selects user from users map by name
	void loadAllUserData(); //loads user data from file
	void displayAllUsers(); //writes all user's info to console
	User* addUser(string username); //adds user to map
	void saveUserScore(string username, int score); //updates user's score history
	void displayUser(); //writes one user's info to console
	void displayUserNames(); //writes all usernames to console
	void writeUserData(); //writes all user data to file
	bool hasUser(string username); //checks if user exists in map

private:
	map<string,User*> all_users; //map of all users
};

}

#endif /* USERDB_H_ */
