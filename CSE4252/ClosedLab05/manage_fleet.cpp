/*
	manage_fleet.cpp
	author: Alec Daling
	date: 3/21/17
*/

#include "drone.h"
#include "autonomous_drone.h"

#include <iostream>
using namespace std;

int main(){
	Drone dumb_drones[5];
	for(int i = 0; i < 5; i++){
		string drone_name = "dumb" + stoi(i+1);
		dumb_drones[i].setDroneName( drone_name );
		dumb_drones[i].setDroneId( dumb_drones[i].getNextDroneSequenceNumber() );
		dumb_drones[i].displayDrone();
	}


}
