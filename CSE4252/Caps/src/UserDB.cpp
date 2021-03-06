/*
 * UserDB.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: Alec Daling
 */
#include "User.h"
#include "UserDB.h"
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <iterator>
namespace caps{
UserDB::UserDB() {
	loadAllUserData();

}

UserDB::~UserDB() {
	// TODO Auto-generated destructor stub
}

void UserDB::loadAllUserData(){
	cout << "Loading user data " << endl;
	string line;
	std::ifstream file("users.txt");
	while(getline(file,line)){
		//create new user
		stringstream lineStream(line);
		//get name
		string name;
		lineStream >> name;
		//get scores
		vector<int> score_hist;
		int value;
		while(lineStream >> value){
			score_hist.push_back(value);
		}
		User* usr = new User(name,score_hist);
		all_users[name] = usr;
	}
}

void UserDB::displayAllUsers(){
	map<string,User*>::iterator it = all_users.begin();
	while(it != all_users.end()){
		it->second->displayUserInfo();
		it++;
	}
}
User* UserDB::addUser(string username){
	User* usr = new User(username);
	all_users[username] = usr;
	return(usr);
}
void UserDB::displayUserNames(){
	map<string,User*>::iterator it = all_users.begin();
	while(it != all_users.end()){
		it->second->displayUserName();
		it++;
	}
}

/*assumes username exists in UserDB (i.e. hasUser() has already been called */
User* UserDB::getUser(string username){
	return(all_users[username]);
}

bool UserDB::hasUser(string username){
	return(all_users.find(username)!=all_users.end());
}

void UserDB::writeUserData(){


	ofstream file;
	file.open("users.txt",std::ofstream::out | std::ofstream::trunc);
	map<string,User*>::iterator it = all_users.begin();
	while(it != all_users.end()){
		string name = it->first;
		User* usr = it->second;
		file << name;
		vector<int> scores = usr->score_history;
		for(unsigned int i = 0; i < scores.size(); i++){
			file << " " << scores[i];
		}
		file << endl;
		it++;
	}
	file.close();
}
void UserDB::saveUserScore(string username, int score){
	all_users[username]->saveScore(score);
}

}

