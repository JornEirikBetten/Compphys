#ifndef TRIDIAGSOLVER_HPP
#define TRIDIAGSOLVER_HPP
#include <armadillo>
#include <string> 
#include <fstream>
#include <string>
#include <cmath>

using namespace std; 
using namespace arma; 

class TriDiagSolver {
protected:
	int _N; 
	vec _g, _x, _v, _a_err, _r_err, _exact; 
public: 
	void initialize(int N, vec f(vec x), vec u(vec x));
	void calculate_error();  
	void write_to_csv(string filename); 
}; 

class GenThomasSolver : public TriDiagSolver {
private: 
	vec _a, _b, _c; 
	void forward_substitution(); 
	void backward_substitution(); 
public: 
	void init(int N, vec f(vec x), vec u(vec x)); 
	void solve(); 
}; 

class SpecThomasSolver : public TriDiagSolver {
private: 
	vec _b; 
	void forward_substitution(); 
	void backward_substitution(); 
public: 
	void init(int N, vec f(vec x), vec u(vec x)); 
	void solve(); 

};


#endif
