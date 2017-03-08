//  file: area_new.cpp
//
//  This program calculates the area of a circle, given the radius.
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02-Jan-2004  original version, for 780.20 Computational Physics
//      01-Jan-2010  updates to "To do" wishlist
//      12-Jan-2016  comment out "using namespace std;"
//		27-Jan-2017  Alec Daling -- Completed To Do Items 1-7
//
//  Notes:  
//   * compile with:  "g++ -o area.x area.cpp"
//
//  To do:
//   1. output the answer with higher precision (more digits)
//   2. use a "predefined" value of pi or generate it with atan
//   3. define an inline square function
//   4. split the calculation off into a function (subroutine)
//   5. output to a file (and/or input from a file)
//   6. add checks of the input (e.g., for non-positive radii)
//   7. rewrite using a Circle class
//
//*********************************************************************// 

// include files
#include <iostream>	     // this has the cout, cin definitions
#include <iomanip>		   //for setprecision in output
#include <math.h>
#include <fstream>			 // for output to file
using namespace std;     // if omitted, then need std::cout, std::cin 

//*********************************************************************//

/*
	Function prototype for item 4. Calculates area of circle.
	Params: #radius - radius of circle
	Returns: area of circle of radius #radius
*/
double circle_area(double radius);

//inline square function defined for item 3
inline double square(double x){
	return(x*x);
}

const double pi = atan(1.)*4;   // define pi as a constant, modified for item 2. 

int
main ()
{
  double radius;    // every variable is declared as int or double or ...

	cout << "Enter the radius of a circle: ";	// ask for radius
  cin >> radius;
  //input check for item 6
	while(true){
  	if(radius < 0){
  	  cout << "Radius must be 0 or positive value. Try again: " << endl;
  		cin >> radius;
  	}else{
			break;
  	}
  }
  
  double area = circle_area(radius);

	//added setprecision(16) to complete Item 1.
  //cout << "radius = " << setprecision(16) << radius << ",  area = " << area;
  //open output file stream for item 5
  ofstream area_out ("area_new.dat"); //output to file "area1.dat"
  //output to file
  area_out << "radius = " << radius << ", area = " << setprecision(16) << area << endl;

  return 0;			// "0" for successful completion
}

//function definitions
double circle_area(double radius){
	//local var declaration
	double area = 0;
	//calculation
	area = pi * square(radius);
	return(area);
}	

//*********************************************************************//
