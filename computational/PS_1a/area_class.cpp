//  file: area_class.cpp
//
//  This program defines a class "Circle", prompts user for radius, and 
//	outputs area of circle.
//
//  Programmer:  Alec Daling
//
//  Revision history:
//      27-Jan-2017  Creation date.
//
//
//*********************************************************************// 

// include files
#include <iostream>	     // this has the cout, cin definitions
#include <iomanip>		   //for setprecision in output
#include <fstream>			 // for output to file
#include <math.h>			   // for atan function in pi calculation
using namespace std;     // if omitted, then need std::cout, std::cin 

//*********************************************************************//

//inline square function defined for item 3
inline double square(double x){
	return(x*x);
}


/*
	Class definition for "Circle" with radius RADIUS and locally calculated PI
*/
class Circle {
	public:
		//variable declarations
		double RADIUS; //radius of circle
		static const double PI;
		
		//member function declarations
		void setRadius(double rad);
		double getArea(void);
};

//class variable definitions
const double Circle::PI = atan(1.)*4;

//Class function definitions
void Circle::setRadius(double rad){
	RADIUS = rad;
}

double Circle::getArea(void){
	return PI * square(RADIUS);
}


int main ()
{

  double radius;    // every variable is declared as int or double or ...
	Circle circle;
	
  cout << "Enter the radius of a circle: ";	// ask for radius
  cin >> radius;
  //input check
	while(true){
  	if(radius < 0){
  	  cout << "Radius must be 0 or positive value. Try again: " << endl;
  		cin >> radius;
  	}else{
			break;
  	}
  }
  circle.setRadius(radius);
  double area = circle.getArea();
	
	//output to terminal (redundant)
  cout << "radius = " << setprecision(16) << radius << ",  area = " << area;
  //open output file stream 
  ofstream area_out ("area_class.dat"); //output to file "area1.dat"
  //output to file
  area_out << "radius = " << radius << ", area = " << setprecision(16) << area << endl;

  return 0;			// "0" for successful completion
}


//*********************************************************************//
