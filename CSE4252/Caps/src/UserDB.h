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
	void loadAllUserData();
	void displayAllUsers();
	void addUser(User);
	void displayUser();
	void displayUserNames();
	void writeUserData();
	map<string,User> all_users;
private:

};

}

#endif /* USERDB_H_ */
