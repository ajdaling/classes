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

int Drone::droneSequenceNumber = 0;    //--> you may initialize static variable here to keep drone ID sequence.

// Implement two constructors: Drone() that initialize data members to zero values
// and Drone(string droneName, int droneId) where droneName is a name assigned to this Drone and the droneId
// is a sequence number to control Drones on inventory, other data members must be set to zero.

Drone::Drone() {
  droneName_ = "";
  roll_ = pitch_ = yaw_ = 0; 		
  distance_ = 0; 			
  batteryVoltage_ = 0;   
}

Drone::Drone(string name, int drone_id) {
  droneName_ = name;
  droneId_ = drone_id;  
  roll_ = pitch_ = yaw_ = 0; 		
  distance_ = 0; 			
  batteryVoltage_ = 0;   
}

Drone::Drone(const Drone &currentDrone) {
  droneName_ = currentDrone.droneName_;
  droneId_ = currentDrone.droneId_;  
  roll_ = pitch_ = yaw_ = 0; 		
  distance_ = 0; 			
  batteryVoltage_ = 0;
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





