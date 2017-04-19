//  file: integ_test.cpp
//
//  This is a test program for basic integration methods.               
//                                                                     
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      04-Jan-2004  original version, for 780.20 Computational Physics
//      08-Jan-2005  changed functions to pass integrand
//      09-Jan-2011  updated functions
//
//  Notes:
//   * define with floats to emphasize round-off error  
//   * compile with:  "g++ -Wall -c integ_test.cpp"
//   * adapted from: "Projects in Computational Physics" by Landau and Paez  
//             copyrighted by John Wiley and Sons, New York               
//             code copyrighted by RH Landau                           
// 
//************************************************************************

// include files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;

#include "integ_routines.h"	// prototypes for integration routines

double my_integrand (double x);

const double ME = 2.7182818284590452354E0;	// Euler's number 

//************************************************************************

int
main ()
{
  // set up the integration specifiction
  const int max_intervals = 3001;	// maximum number of intervals
  const double lower = 0.0;	// lower limit of integration
  const double upper = 1.0;	// upper limit of integration

  //const double answer = 1. - 1. / ME;	// the "exact" answer for the test 
  const double answer = 0.090764757986754820593;
  double result = 0.;  // approximate answer

  // open the output file stream
  
  ofstream milne_out;
  milne_out.open("milne.dat");
  ofstream simpson_out;
  simpson_out.open("simpson.dat");

  // Simpson's rule requires an odd number of intervals  
  for (int i = 3; i <= max_intervals; i += 2)
  {
    simpson_out << setw(4) << log10( i );

    result = simpsons_rule (i, lower, upper, &my_integrand);
    simpson_out << "  " << scientific << log10 ( fabs(result - answer) / answer );

    simpson_out << endl;
  }
  
  //milne's rule requires 4i+1 intervals (5,9,13,17...)
    for (int i = 5; i <= max_intervals; i += 4)
  {
    milne_out  << setw(4) << log10( i );

		result = milnes_rule(i,lower,upper,&my_integrand);
		milne_out << "  " << scientific << log10( fabs(result - answer) / answer);

    milne_out << endl;
  }

	
  cout << "data stored in milne.dat and simpson.dat\n";
  //integ_out.close ();
	milne_out.close();
	simpson_out.close();
  return (0);
}

//************************************************************************

// the function we want to integrate 
double
my_integrand (double x)
{
  //return (exp (-x));
  double t1 = exp(-pow(x,3.));
  //cout << "t1 " << t1 << endl;
  double t2 = pow(1.+pow(x,2.),.5);
  //cout << "t2 " << t2 << endl;
  double t3 = (log10(1.+pow(x,2.)));
  //cout << "t3 " << t3 << endl;
  return( t1 * t2 * t3 );
}

