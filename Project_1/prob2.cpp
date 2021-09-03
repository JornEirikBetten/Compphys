
#include <armadillo>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace arma; 
using namespace std; 




//function calculating values of analytical expression of u(x) 
vec function_u(int n, vec x) {
	vec u = zeros<vec>(n+1); 
	for (int i=0; i<n+1; i++) {
		double u_i = 1.0-(1.0-exp(-10))*x(i)-exp(-10*x(i)); 
		u(i) = u_i;
	}
	return u; 
}



int main()
{	
	int n = 100; //number of data points -1
	double l = 1.0; //length of x-range
	double h = l/n; //space between each data point on the x-axis
	// initializing vectors
	vec u = zeros<vec>(n+1);
	vec x = zeros<vec>(n+1);
	// filling x with appropriate values in the range 0 to 1
	for (int i=0; i<n+1; i++) {
		double x_i = i*h;
		x(i) = x_i;
	}
	// calculating values of u
	u = function_u(n, x); 
	ofstream file; 
	file.open("exact.csv"); //comma-separated values for easy access in pandas
	file << "x,exact_u\n";
	file.precision(4); //four decimals 
	file << scientific; //scientific notation
	for (int i=0; i<n+1; i++) {
		file << x(i) << "," << u(i) <<"\n";
	}
	return 0; 
}


