/* Class Drone Specification file  
   Header file autonomous_drone.h declares class Autonomous_Drone.
Class Prototype that models an experimental autonomous Drone 
It is an updated version of a drone that includes a GPS sensor
*/   

#ifndef  AUTONOMOUS_DRONE_H 
#define  AUTONOMOUS_DRONE_H

#include  <iostream>
using namespace std;


class AutonomousDrone: public Drone
{
public:
  AutonomousDrone(); 				// default constructor
  AutonomousDrone(string name, int drone_id, float longitud, float latitud);
  AutonomousDrone(AutonomousDrone &currentDrone);
  ~AutonomousDrone();
  void displayDrone();
  void setCourse(float latitud, float longitud);

 
  
protected:
  float latitud_ , longitud_; 		// unit is degrees, measured by GPS units
  
};

#endif
