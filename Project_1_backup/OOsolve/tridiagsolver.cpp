#include "tridiagsolver.hpp"






//Initializing problem, giving x and g values. 

void TriDiagSolver::initialize(int N, vec f(vec x), vec u(vec x)) {
	_N = N; 
	double dx = 1.0/(_N+1); 
	_x = linspace(dx, 1-dx, _N); // [dx, ... , 1-dx] x0 and xn are not included
	_g = vec(_N); 
	_v = vec(_N); 
	_g = dx*dx*f(_x); 
	_a_err = vec(_N);
	_r_err = vec(_N);
	_exact = vec(_N);
	_exact = u(_x); 

}

void TriDiagSolver::calculate_error() {
	_a_err = _v - _exact; 
	for (int i = 0; i<_N; i++) {
		_a_err(i) = abs(_a_err(i)); 
		if (_exact(i)== 0) {
			_r_err(i) = 0; 
		}
		else {
			_r_err(i) = abs (_a_err(i)/_exact(i)); 
		}
	}
}

// writing x and v values to csv file
void TriDiagSolver::write_to_csv(string filename) {
	ofstream file; 
	file.open(filename); 
	file << "x,u(x),abs_error, rel_error\n"; 
	file.precision(4); 
	file << scientific; 
	file << 0.0000e+0 << "," << 0.0000e+0 << "," << 0.0000e+0 <<"," << 0.0000e+0 << "\n"; 
	for (int i=0; i<_N; i++) {
		file << _x(i) << "," << _v(i) << "," << _a_err(i) << "," << _r_err(i) << "\n"; 
	}  
	file << 1.0000e+0 << "," << 0.0000e+0 << "," << 0.0000e+0 << "," << 0.0000e+0 <<"\n"; 

}
