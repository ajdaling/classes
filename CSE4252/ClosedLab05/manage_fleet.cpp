/*
	manage_fleet.cpp
	author: Alec Daling
	date: 3/21/17
*/

#include "drone.h"
#include "autonomous_drone.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct missing_drone {
	int id;
	int longitude;
	int latitude;
};

//function prototypes
int get_command();
void send_drone(AutonomousDrone* adrone, Drone mdrone, int longitude, int latitude);
void show_drones(Drone nDrones[], AutonomousDrone aDrones[]);
void report_missing_drone(AutonomousDrone* drone);
void report_missing_drone(Drone* drone, int lat, int lon);

int main(){

	missing_drone missing_drones[10];
	int num_missing_drones = 0;

	//create 5 dumb drones
	Drone dumb_drones[5];
	string dumb_base = "dumb";
	for(int i = 0; i < 5; i++){
		char numstr[21];
		sprintf(numstr,"%d",i+1);
		string drone_name = dumb_base + numstr;
		dumb_drones[i].setDroneName( drone_name );
		dumb_drones[i].setDroneId( dumb_drones[i].getNextDroneSequenceNumber() );
	}

	//create 5 smart "autonomous" drones
	AutonomousDrone smart_drones[5];
	string smart_base = "smart";
	for(int i = 0; i < 5; i++){
		char numstr[21];
		sprintf(numstr,"%d",i+1);
		string drone_name = smart_base + numstr;
		smart_drones[i].setDroneName( drone_name );
		smart_drones[i].setDroneId( smart_drones[i].getNextDroneSequenceNumber() );
        smart_drones[i].setCourse(111.*float(i),111.*float(i+1));
	}

	int cmd;

	bool keep_going = true;
	while(keep_going){
		cmd = get_command();
		switch(cmd){
		case(1):{
			//show drones
			show_drones(dumb_drones,smart_drones);
			break;
			}
		case(2):{
			//report missing drone
			//prompt user for id
			int missing_id;
			cout << "Enter ID of missing drone." << endl;
			cin >> missing_id;
			//input check
			while(cin.fail() || missing_id > 10 || missing_id < 1){
				cout << "Invalid ID. Enter a number 1-10." << endl;
				cin >> missing_id;
			}
			
      //add to missing_drones record
      missing_drones[num_missing_drones].id = missing_id;
			if(missing_id > 5){
				//missing drone is autonomous
				missing_drones[num_missing_drones].latitude = smart_drones[missing_id-6].getLatitude();
				missing_drones[num_missing_drones].longitude = smart_drones[missing_id-6].getLongitude();
				report_missing_drone(&smart_drones[missing_id-6]);
			} else {
				//missing drone is not autonomous so prompt for last known coordinates
				int lon = 0, lat = 0;
				cout << "Enter last known coordinates." << endl;
				cout << "Enter Latitude: " << endl;
				cin >> lat;
				cout << "Enter Longitude: " << endl;
				cin >> lon;
				missing_drones[num_missing_drones].latitude = lat;
        missing_drones[num_missing_drones].longitude = lon;
				report_missing_drone(&dumb_drones[missing_id-1], lat, lon);
			}
			num_missing_drones++;
			break;
            }
		case(3):{
			//send autonomous drone
			int mID;
			cout << "Enter ID of missing drone." << endl;
			cin >> mID;

			bool mID_is_missing = false;
			while(!mID_is_missing){
				int i = 0;
				
			}

			//Determine which autonomous drone (if any) to send
			bool found_aDrone = false;
			int aID = 0;
			for(int i = 6; i <= 10; i++){
				bool not_lost = true;
				for(int j = 0; j < num_missing_drones; j++){
					if(missing_drones[j].id == i){
						not_lost = false;
					}
				}
				if(not_lost){
					found_aDrone = true;
					aID = i;
					break;
				} else if(i == 10){
					cout << "No Autonomous Drones Available";
					break;
				}
			}

			int missing_lat, missing_lon = 0;
			if(found_aDrone){
				//get coordinates of missing drone
				for(int i = 0; i <= num_missing_drones; i++){
					if(missing_drones[i].id == mID){
						missing_lat = missing_drones[i].latitude;
						missing_lon = missing_drones[i].longitude;
					}
				}
				if(mID <= 5){
					send_drone(&smart_drones[aID-6], dumb_drones[mID-1], missing_lat, missing_lon);
				} else{
					send_drone(&smart_drones[aID-6], smart_drones[mID-6], missing_lat, missing_lon);
				}
			}
			break;
			}

		case(4):{
			cout << "Goodbye" << endl;
			keep_going = false;
			break;
			}
        }

    }


    return(0);
}


void show_drones(Drone dumb_drones[],AutonomousDrone smart_drones[]){
    //show dumb drones
    for(int i = 0; i < 5; i++){
        dumb_drones[i].displayDrone();
        cout << endl;
    }
    //show smart drones
    for(int i = 0; i < 5; i++){
        smart_drones[i].displayDrone();
        cout << endl;
    }
}


void report_missing_drone(AutonomousDrone* drone){
    cout << "Drone ";
    drone->displayDrone();
    cout << " IS MISSING. " << endl;
    cout << "Last known coordinates are: " << endl;
    drone->displayCourse();
}

void report_missing_drone(Drone* drone, int lat, int lon){
    cout << "Drone ";
    drone->displayDrone();
    cout << " IS MISSING. ";
    cout << "Last known coordinates are: " << endl;
    cout << "Latitud=" << lat << "	Longitud=" << lon << endl;
}

int get_command(){

	int command;

	cout << "Enter Command: " << endl;
	cout << "		1: Show drones." << endl;
	cout << "		2: Report Missing Drone." << endl;
	cout << "		3: Send Autonomous Drone." << endl;
	cout << "		4: Exit." << endl;

	//input check
	cin >> command;
	while(cin.fail()){
		cout << "Invalid Command. Enter a number 1-4." << endl;
		cin >> command;
	}

	return(command);
}


void send_drone(AutonomousDrone* adrone, Drone mdrone, int longitude, int latitude){
    //cout << "Changing coordinates of drone: ";
    //adrone->displayDrone();
	adrone->setCourse(longitude, latitude);
	//adrone->displayDrone();
	cout << "Autonomous ";
	adrone->displayDrone();
	cout << " WAS SENT TO MISSING DRONE LOCATION" << endl;
	cout << "Missing ";
	mdrone.displayDrone();
	cout << endl;
}
