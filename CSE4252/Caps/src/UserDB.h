/*
 * UserDB.h
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
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
	User* getUser(string username);
	void loadAllUserData();
	void displayAllUsers();
	User* addUser(string username);
	void saveUserScore(string username, int score);
	void displayUser();
	void displayUserNames();
	void writeUserData();
	bool hasUser(string username);

private:
	map<string,User*> all_users;
};

}

#endif /* USERDB_H_ */
