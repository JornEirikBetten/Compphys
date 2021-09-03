#ifndef TRIDIAGSOLVER_HPP
#define TRIDIAGSOLVER_HPP
#include <armadillo>
#include <string> 
#include <fstream>
#include <string>

using namespace std; 
using namespace arma; 

class TriDiagSolver {
protected:
	int _N; 
	vec _g, _x, _v; 
public: 
	void initialize(int _N, vec f(vec _x)); 
	void write_to_csv(string filename); 
}; 

class GenThomasSolver : public TriDiagSolver {
private: 
	vec _a, _b, _c; 
	void forward_substitution(); 
	void backward_substitution(); 
public: 
	void init(int N, vec f(vec x)); 
	void solve(); 
}; 

#endif
