/*
	Results:
	
	The plot (plot_sum.plt) exhibits three fairly linear (log-log) regions. Up to ~N=10^5 the 
	relative error goes as N^1/2 with sigificant devation. Between 10^5 and 10^7 eps~N^2, and the error flattens out (N^0) 
	above N=10^7.
	
*/



/*
	Alec Daling -- 27 Jan 2017
	Program generates data file comparing two summation methods (sum-up and sum-down) for 1/n.
	Calculates relative error between two methods as a function of the number of terms used
	in the summations.
	
	The downward sum is more precise because each iteration involves the sum of a very high
	precision number to a number of slightly lower precision. The sum up starts with the lowest 
	possible precision (depending on your start value and number of terms) and tries to add 
	continually higher precision numbers. Doing this results in a loss of precision with 
	every iteration. 
*/



//include files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
	//variable declarations
	float s_up = 0;	//sum up result
	float s_down = 0; //sum down result
	int num_terms; //N 
	float rel_err;
	
	//open output stream
	ofstream fout("sum1.dat");
	//output column headers
	fout << "#N     sum_up	        sum_down          rel_error" << endl;
	// loop increasing num_terms (N)
	for(num_terms = 100; num_terms <= 1e9; num_terms *= 2 ){
		//reset sums each iteration
		s_up = 0;
		s_down = 0;
		//sum up 
		for(int n = 1; n <= num_terms; n++){
			s_up += 1./n;
		}
	
		//sum down
		for(int n = num_terms; n >= 1; n--){
			s_down += 1./n;
		}
	//calculate relative difference
	rel_err = fabs(s_up - s_down) / (0.5 *(fabs(s_up) + fabs(s_down)));
	//output to file
	fout << scientific << log10(num_terms) << "    " << setprecision(16) << log10(s_up) 
		<< "    " <<  setprecision(16) << log10(s_down)	
		<< "    " << scientific << log10(rel_err) << endl;

	}
	return(0);
}
