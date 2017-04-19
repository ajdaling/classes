//  file: gsl_spline_test_class.cpp
// 
//  Test program for the gsl spline routines using the Spline class
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02/10/09 -- created from gsl_cubic_spline_test.cpp
//
//  Notes:
//   * uses the GSL interpolation functions (see online documentation) 
//
//*****************************************************************
// include files
#include <iostream>    // cout and cin
#include <iomanip>     // manipulators like setprecision
#include <cmath>
#include <string>     // C++ strings    
#include <fstream>                             
using namespace std;    
#include "GslSpline.h"  // Header file for the GSL Spline class

inline double sqr (double z) {return z*z;}  // inline function for z^2

double get_th(double e);

int
main (void)
{
	//output file stream
	ofstream out;
	out.open("gsl_spline_test.dat");

  //const int NMAX = 300;   // maximum number of array points 
  //double x_values[NMAX], y_values[NMAX];
	double npts = 9;
	double x_values[9] = {0.,25.,50.,75.,100.,125.,150.,175.,200.};
	double y_values[9] = {10.6,16.0,45.0,85.5,52.8,19.9,10.8,8.25,4.7};

	/*
  // Test: interpolate y = sin(x^2) from xmin to xmax with npts points 
  double xmin = 1.;
  double xmax = 3.;
  int npts = 20;
  double deltax = (xmax - xmin)/double(npts-1);
  for (int i = 0; i < npts; i++)
  {
    double x_temp = xmin + double(i) * deltax;   // grid of x points
    x_values[i] = x_temp;
    y_values[i] = sin (x_temp * x_temp);
  }
	*/
	
	
  // Make the spline object
  //string type = "cubic";
  Spline my_cubic_spline (x_values, y_values, npts, "cubic");
  Spline my_linear_spline (x_values, y_values, npts, "linear");
  Spline my_poly_spline (x_values, y_values, npts, "polynomial");
	out << "# x  linear  polynomial  cubic exact" << endl;
	for(int x = 0.; x <= 200.; x+= 5.){
		out << "  "<< x << " " << fixed << setprecision(5) <<  my_linear_spline.y(x) << " " << my_poly_spline.y(x) << " " << my_cubic_spline.y(x) << " " << get_th(x) << endl;
	}

	/*
  double x;
  cout << "Enter x: ";
  cin >> x;    // test point 

  // Evaluate the spline and derivatives
  double y = my_cubic_spline.y (x);
  double y_deriv = my_cubic_spline.yp (x);
  double y_deriv2 = my_cubic_spline.ypp (x);

  double x_sq = sqr(x);

  cout << "    x     y_exact   y_spline   y'_exact  y'_spline";
  cout << "  y''_exact  y''_spline" << endl;
  cout << fixed << setprecision(6) 
       << x << "  " << sin(x_sq) << "  " <<  y << "  "
       <<  2.*x*cos(x_sq) << "  " << y_deriv << "  "
       <<  -4.*x_sq* sin(x_sq) + 2.*cos(x_sq) << "  " <<  y_deriv2
       << endl;
	*/
	
	
	
  return (0);      // successful completion 
}

double get_th(double e){
	double gamma = 55.;
	double sigma0 = 63900.;
	double er = 78.;
	double den_left = sqr(e - er);
	double den_right = sqr(gamma) / 4.;
	double den = den_left + den_right;
	return(sigma0 / den);
}

