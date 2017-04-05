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
     
  Drone *d1;
   
  cout <<"Enter name :"<<endl;
  getline(cin, Name);
  cout <<"Enter id :"<<endl;
  cin >> id;
           
  d1 = new Drone(Name,id);
  list.push_back(*d1);
  cin.get(); //clear buffer
  
  
/* Example of setting up an iterator to loop through the list
  std::list<Drone>::iterator it;
  for ( it = list.begin(); it != list.end(); it++ ) {
    // For each Drone, print out their info
    it->displayDrone();
  }
*/


// THE FOLLOWING SECTION IS TO BE IMPLEMENTED IN EXERCISE 2
// Show what is the address of the drone vector


// Show the size of the vector


// Show the drone in position [2]


// Show the first and last drone 


 
  return 0;
}

