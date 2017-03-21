/* Class Drone implementation file  
 Class Prototype that models an experimental Autonomous Drone 
Itś derived from the Drone class and includes a GPS device 
*/

// Include section. Add any header, library, namespace that you may need
#include "drone.h"
#include "autonomous_drone.h"
#include  <iostream>
using namespace std;



// Implement two constructors: AutonomousDrone() that initialize data members to zero values
// and AutonomousDrone(string droneName, int droneId, double longitud, double latitud) where droneName is a name 
//assigned to this Drone and the droneId is a sequence number to control Drones on inventory, other data members must be 
//set to zero.

AutonomousDrone::AutonomousDrone() {
	droneName_ = "";
	roll_ = pitch_ = yaw_ = 0;
	distance_ = 0;
	batteryVoltage_ = 0;
	longitud_ = latitud_ = 0;
}

AutonomousDrone::AutonomousDrone(string name, int drone_id, float longitud, float latitud) {
	droneName_ = name;
  droneId_ = drone_id;  
  roll_ = pitch_ = yaw_ = 0; 		
  distance_ = 0; 			
  batteryVoltage_ = 0; 
  latitud_ = latitud;
  longitud_ = longitud;
}

AutonomousDrone::AutonomousDrone(AutonomousDrone &currentDrone) {
  droneName_ = currentDrone.droneName_;
  droneId_ = currentDrone.droneId_;
  roll_ = pitch_ = yaw_ = 0;
  batteryVoltage_ = 0;
  latitud_ = longitud_ = 0;
  distance_ = 0;
}

void AutonomousDrone::displayDrone() {
	cout << "Drone: " << droneName_ << "  id: " << droneId_ << " Long: " << longitud_ << " Lat: " << latitud_; 
}

void AutonomousDrone::setCourse(float longitud, float latitud) {
	longitud_ = longitud;
	latitud_ = latitud;
}

void AutonomousDrone::displayCourse(){
	cout << "Latitude=" << latitud_ << "		Longitude=" << longitud_ << endl;
}

AutonomousDrone::~AutonomousDrone() {
  
}

int AutonomousDrone::getLongitude(){
	return(longitud_);
}

int AutonomousDrone::getLatitude(){
	return(latitud_);
}

