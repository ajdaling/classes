/* my_drone.cpp
  author: Alec Daling
  date: 3/21/17
  Explain what it does, classes used, special conditions

*/


#include "drone.h"
#include "autonomous_drone.h"

#include  <iostream>
using namespace std;


int main()
{
	//create autonomous drone called Sprit1 using default constructor
	AutonomousDrone* Spirit1 = new AutonomousDrone();
	//assing name and ID
	cout << "Creating Spiri1" << endl;
	Spirit1->setDroneName("Spirit1");
	Spirit1->setDroneId(Spirit1->getNextDroneSequenceNumber());
	Spirit1->displayDrone();
	cout << "Changing course to 100,150" << endl;
	Spirit1->setCourse(100,150);
	Spirit1->displayDrone();
	//test implemented functions
	
	cout << "Creating Spirit2" << endl;
	//create Spirit2 using second constructor
	AutonomousDrone* Spirit2 = new AutonomousDrone("Spirit2", Spirit1->getNextDroneSequenceNumber(), 0, 0);
	//display Spirit2's state
	Spirit2->displayDrone();
	
	return(0);


}

