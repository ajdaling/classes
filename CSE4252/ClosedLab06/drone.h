/* Class Drone Specification file  
   Header file Drone.h declares class Drone.
Class Prototype that models an experimental Drone 
The aircraft has a battery to operate (its voltage must be monitored), 
an IMU sensor (Inertial Measurement Unit) that measures Euler angles for roll, pitch, and yaw;
a Lidar sensor -proximity sensor- which measures distance in centimeters,
four motors that move the drone to a specific location and
an onboard computer controller

*/   

#ifndef  DRONE_H 
#define  DRONE_H

#include  <iostream>
using namespace std;


class Drone
{
public:
  Drone(); 				// default constructor
  Drone(string name, int drone_id);
  Drone(const Drone& currentDrone);
  void setDroneName(string name);
  void setDroneId(int drone_id);
  void displayDrone();
  static int getNextDroneSequenceNumber();
  void update_sensor_values(float r, float p, float y, int d, float v);
  float get_batteryVoltage() const;
  bool operator<(const Drone& d1) const;
  bool operator==(const Drone& d1) const;
  Drone operator+(const Drone& d1) const;
  int Compare(const Drone& d) const;
  static int droneSequenceNumber;
  
protected:
  string droneName_;
  int droneId_;  
  float roll_, pitch_, yaw_; 		// unit is degrees, measured by IMU
  int distance_; 			// unit is cm, measured by Lidar.
  float batteryVoltage_; 		// unit is Volts
};

#endif
