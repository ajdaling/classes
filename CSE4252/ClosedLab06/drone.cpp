/* Class Drone implementation file  
 Class Prototype that models an experimental Drone 
The aircraft has a battery to operate (its voltage must be monitored), 
an IMU sensor (Inertial Measurement Unit) that measures Euler angles for roll, pitch, and yaw;
a Lidar sensor -proximity sensor- which measures distance in centimeters,
four motors that move the drone to a specific location and
an onboard computer controller

*/

// Include section. Add any header, library, namespace that you may need
#include "drone.h"
#include  <iostream>
using namespace std;

int Drone::droneSequenceNumber = 0;    //--> you may initialize static variable here.

// Implement two constructors: Drone() that initialize data members to zero values
// and Drone(string droneName, int droneId) where droneName is a name assigned to this Drone and the droneId
// is a sequence number to control Drones on inventory, other data members must be set to zero.

Drone::Drone() {
  droneName_ = "";
  roll_ = pitch_ = yaw_ = 0; 		
  distance_ = 0; 			
  batteryVoltage_ = 13.5;   
}


Drone::Drone(string name, int drone_id) {
  droneName_ = name;
  droneId_ = drone_id;  
  roll_ = pitch_ = yaw_ = 0; 		
  distance_ = 0; 			
  batteryVoltage_ = 13.5;   
}

Drone::Drone(const Drone& currentDrone) {
  droneName_ = currentDrone.droneName_;
  droneId_ = currentDrone.droneId_;  
  roll_ = currentDrone.roll_;
  pitch_ = currentDrone.pitch_;
  yaw_ = currentDrone.yaw_; 		
  distance_ = currentDrone.distance_; 			
  batteryVoltage_ = currentDrone.batteryVoltage_;
}


void Drone::setDroneName(string name) {
  droneName_ = name;
}

void Drone::setDroneId(int drone_id) {
  droneId_ = drone_id;
}

void Drone::displayDrone() {
  cout << "Drone: " << droneName_ << "  id: " << droneId_ << endl;
}

int Drone::getNextDroneSequenceNumber() {
  Drone::droneSequenceNumber = Drone::droneSequenceNumber + 1;
  return Drone::droneSequenceNumber;
}


// This member method updates the member variables with data from the sensors 
// Roll, Pitch and Yaw units are degrees, measured by IMU. Distance units are cm, measured by Lidar.
// Battery Voltage units are voltage.

void Drone::update_sensor_values(float r, float p, float y, int d, float v) {
  roll_ = r;
  pitch_ = p;
  yaw_ = y;
  distance_ = d; 			
  batteryVoltage_ = v;
}

// This function tests if two Drones are equal
// It is the operator==( ) overloading function to test equality
// Return true, if the two objects have the same ID

/*bool Drone::operator==(const Drone& d1) const
{
  return false;
}
*/

// The following function is the overloading operator<( ) and is required for comparing Drone objects and support
// functions like the sort operation

/*bool Drone::operator<(const Drone& d1) const
{
  return false;
}
*/

// The function Compare() compares two drones: drone1.Compare(drone2). 
// The function must return an integer value 0 if they are equal, 
// 1 if drone1 is > drone 2 and -1 if drone 1 < drone2. 

/*
int Drone::Compare(const Drone& d) const {
  return 0;
}

*/

