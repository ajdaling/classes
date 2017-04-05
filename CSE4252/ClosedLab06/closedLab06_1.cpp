/****************************************

This program stores Drone objects in a list


*********************************************/
#include <iostream>
#include <list>
#include <string>
#include "drone.h"

using namespace std;


int main()
{
   // Create a list of Drone objects
  std::list<Drone> list;
  string Name;
  int id; 

	//a. make one drone per quadrant (5 quadrants, despite the use of the word quadrant).
	for(int i = 0; i <= 4; i++){
		cout << "Enter name :" << endl;
		getline(cin,Name);
		cout << "Enter id:" << endl;
		cin >> id;
		
		Drone *drn;
		drn = new Drone(Name,id);
		list.push_back(*drn);
		cin.get();
	}

/* b. sort and display in ascending order 
	On first attempt, gives compiler error because operator< is undefined.
	After defining operator< as member function, works.
*/
	cout << "*************************" << endl;
	cout << "Testing sort function" << endl;
	cout << "prior to sort" << endl;
	//display drones in initial order
	std::list<Drone>::iterator it;
  for ( it = list.begin(); it != list.end(); it++ ) {
    // For each Drone, print out their info
    it->displayDrone();
  }
  
	list.sort();	//sort list of drones in ascending order
	cout << "After sort" << endl;
	//print drones in ascending order
	std::list<Drone>::iterator it2;
  for ( it2 = list.begin(); it2 != list.end(); it2++ ) {
    // For each Drone, print out their info
    it2->displayDrone();
  }
  
	cout << endl << endl << "*************************" << endl;
	cout << "Testing overload operator:" << endl;

/* c. implement and test overloading operator  */
	std::list<Drone>::iterator it3;
	std::list<Drone>::iterator it4;
	for(it3 = list.begin(); it3 != list.end(); it3++){
		for(it4 = list.begin(); it4 != list.end() ; it4++){
			if(*it3 == *it4 && it3 != it4){
				cout << "These two drones have the same ID: " << endl;
				it3->displayDrone();
				it4->displayDrone();
			}
		}
	}
	cout << "****************************" << endl << endl;
	
/* d. implement and test Compare() function  */
	cout << "Testing Compare() function " << endl;
	std::list<Drone>::iterator it5;
	it5 = list.begin();
	it5++; //set it5 to second drone in list
	std::list<Drone>::iterator it6;
	for(it6 = list.begin(); it6 != list.end() ; it6++){
			it5->displayDrone();
			it6->displayDrone();
			cout << it5->Compare(*it6) << endl;
	}
	cout << "End Ex. 1" << endl;

// THE FOLLOWING SECTION IS TO BE IMPLEMENTED IN EXERCISE 2
// Show what is the address of the drone vector


// Show the size of the vector


// Show the drone in position [2]


// Show the first and last drone 


 
  return 0;
}

