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
   
}

AutonomousDrone::AutonomousDrone(string name, int drone_id, float longitud, float latitud) {
  
}

AutonomousDrone::AutonomousDrone(AutonomousDrone &currentDrone) {
  
}

void AutonomousDrone::displayDrone() {

}

void AutonomousDrone::setCourse(float longitud, float latitud) {

}


AutonomousDrone::~AutonomousDrone() {
  
}



