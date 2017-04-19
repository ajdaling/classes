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

double uofr(double r);
double uofrp(double r);

int
main (void)
{
	//output file stream
	ofstream out;
	out.open("gsl_spline2.dat");

	bool done = false;
	int npts = 10;
	while(!done){
		double x_values[npts], y_values[npts];
		for(int i = 0; i < npts; i++){
			double r = 1. + (double(i) * (3. / double(npts-1) ));
			x_values[i] = r;
			y_values[i] = uofr(r);
		}
		//begin spline
		Spline my_cubic_spline (x_values, y_values, npts, "cubic");
		
		int nn = 100;
		double avg_err = 0.;
		double total_err = 0.;
		for(int i = 0; i < nn-1; i++){
			double x = 1. + (double(i) * (3. / double(nn-1) ));
			//cout << "yp(" << x << ") is: " << my_cubic_spline.yp(x) << endl;
			total_err += my_cubic_spline.yp(x) - uofrp(x);
		}
		avg_err = abs(total_err) / (double(nn));
		cout << "Average error with " << npts << " points is: " << avg_err << endl;
		if(avg_err < 1./1000000.){
			cout << "DONE!!!. You need " << npts << " points." << endl;
			done = true;
		} else {
			npts += 10;
		}
	}
	
/*  
	out << "# x cubic exact" << endl;
	for(int x = 0.; x <= 200.; x+= 5.){
		out << "  "<< x << " " << fixed << setprecision(5) <<  my_linear_spline.y(x) << " " << my_poly_spline.y(x) << " " << my_cubic_spline.y(x) << " " << get_th(x) << endl;
	}
*/
	
  return (0);      // successful completion 
}

double uofr(double r){
	return(2. * r * exp(-1.*r));
}

double uofrp(double r){
	double u = (-2.* exp(-1. * r)) * (r - 1.);
	//cout << "uofrp(" << r << ") is: " << u << endl;
	return(u);
}

