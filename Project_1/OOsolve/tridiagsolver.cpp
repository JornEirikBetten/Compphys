#include "tridiagsolver.hpp"






//Initializing problem, giving x and g values. 

void TriDiagSolver::initialize(int N, vec f(vec x)) {
	_N = N; 
	double dx = 1.0/(_N+1); 
	_x = linspace(dx, 1-dx, _N); // [dx, ... , 1-dx] x0 and xn are not included
	_g = vec(_N); 
	_v = vec(_N); 
	_g = dx*dx*f(_x); 

}


// writing x and v values to csv file
void TriDiagSolver::write_to_csv(string filename) {
	ofstream file; 
	file.open(filename); 
	file << "x,u(x)\n"; 
	file.precision(4); 
	file << scientific; 
	for (int i=0; i<_N; i++) {
		file << _x(i) << "," << _v(i) << "\n"; 
	} 

}
