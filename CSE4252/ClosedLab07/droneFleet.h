/* Class Template for fleet of different Drone types
   This file serrves as Header file and also includes the implementation.
*/
 

#ifndef  DRONEFLEET_H 
#define  DRONEFLEET_H

#include  <iostream>
using namespace std;

#define MAX_LENGTH 5

template<class T> 
class DroneFleet
{
public:

// DroneFleet() 
// Implement this constructor. 
// It should create the fleet -array- of a size of MAX_LENGTH
// the lenght should be initialized to zero
DroneFleet() {                   // Constructor
}

// void Insert(T item ) 
// Implement this class member function. 
// Input paratemer(s): any type of drone object
// The function inserts the drone type object provided into the next available position in the fleet
// No return value 

void Insert(T item ) {
}

// void Print() 
// Implement this class member function. 
// Input paratemer(s): None
// The function displays in the screen each object in the fleet
// No return value. It does not modify the fleet

void Print() {
}

protected:
  int length;
  T fleet[MAX_LENGTH];
};

#endif

