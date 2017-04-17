// Program to create fleets of different type of drones
// 
//                   

#include <cstdio>
#include <cstdlib>
#include "drone.h"
#include "autonomous_drone.h"
#include "closedLab07_3.cpp"
#include <iostream>
using namespace std;

int main()
{

  int sequence = 0;

  Drone d1("north", 1);
  Drone d2("South", 2);
  Drone d3("east",3);
  Drone d4("west",4);
  Drone d5("center",5);
  AutonomousDrone ad1("north", 10, 15, 30);
  AutonomousDrone ad2("south", 20, 15, 32);

	//create fleet of drones
	DroneFleet<Drone>* dFleet = new DroneFleet<Drone>();
	dFleet->Insert(d1);
	dFleet->Insert(d2);
	dFleet->Insert(d3);
	dFleet->Insert(d4);
	dFleet->Insert(d5);
	
	//create fleet of autonomous drones
	DroneFleet<AutonomousDrone> adFleet;
	adFleet.Insert(ad1);
	adFleet.Insert(ad2);
	
	//print fleets
	dFleet->Print();
	adFleet.Print();

	  
 
  return 0;
}
