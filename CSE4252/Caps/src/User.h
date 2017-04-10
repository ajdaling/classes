/*
 * User.h
 *
 *  Created on: Apr 10, 2017
 *      Author: aj
 */

#ifndef USER_H_
#define USER_H_
#include <string>
using namespace std;


namespace caps{
class User {
public:
	User(string name);
	virtual ~User();
	string getName();
	int high_score;
private:
	string user_name;

};


}

#endif /* USER_H_ */


