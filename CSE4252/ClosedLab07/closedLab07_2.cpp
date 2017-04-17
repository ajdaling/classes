/****************************************
	closedLab07_1.cpp
	Author: Alec Daling
	Date: 4/17/17
	
This program does ............


*********************************************/
#include <iostream>
#include <fstream>	// for file operations
#include <stdlib.h> 	// for exit() functions
#include <vector>
#include "drone.h"
#include <cstring>
#include <list>
#include <queue>
#include <ctype.h>
#include <stdio.h>


using namespace std;


int main()
{

  ifstream readFile;
  ofstream writeFile;

  readFile.open("droneDatabase.txt",ios::in);
  if (!readFile.is_open()) {
    cerr << "Unable to open file "<< readFile << endl;
      exit(10);
    }
	
	string outFile;
	cout << "Enter output file name: ";
	getline(cin,outFile);
	writeFile.open(outFile.c_str(),ostream::out | ofstream::trunc);
  if (!writeFile.is_open()) {
    cerr << "Unable to open file "<< writeFile << endl;
      exit(10);
    }

	vector<string> buff;
	string mydata;
  while(! readFile.fail() && ! writeFile.fail()) {
    getline(readFile, mydata);
    if(!mydata.empty()){
    	writeFile << mydata << endl;
    	buff.push_back(mydata);
    }
  }
  
	//create vector of drones
	vector<Drone> drone_vec;
	int i = 0;
	while(i < buff.size()){
		//get name and id
		string drone_name = buff[i];
		i++;
		string drone_id = buff[i];
		//create new drone
		Drone* drn = new Drone(drone_name, atoi(drone_id.c_str()));
		//add drone to vector
		drone_vec.push_back(*drn);
		i++;
	}

	//loop to offer to save more drones
	bool keep_going = true;
	while(keep_going){
		cout << "There are " << drone_vec.size() << " drones saved. Would you like to add more? (y/n)" << endl;
		string response1;
		cin >> response1;
		if(response1.compare("y") == 0){
			cout << "Enter drone name: ";
			string drone_name;
			cin >> drone_name;
			cout << "Enter drone id: ";
			string drone_id;
			cin >> drone_id;
			
			//add to output file
			writeFile << drone_name << endl;
			writeFile << drone_id << endl;
			
			Drone* temp_drone = new Drone(drone_name,atoi(drone_id.c_str()));
			drone_vec.push_back(*temp_drone);
		} else{
			keep_going = false;
		}
	} 
	
	
	
  readFile.close();
  writeFile.close();
}


