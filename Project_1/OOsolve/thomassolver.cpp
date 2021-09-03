#include "tridiagsolver.hpp"



void GenThomasSolver::init(int N, vec f(vec x)) {
	initialize(N, f); 
	_a = vec(_N).fill(-1.); 
	_b = vec(_N).fill(2.); 
	_c = vec(_N).fill(-1.); 
	_v = vec(_N).fill(0.); 
}


void GenThomasSolver::forward_substitution() {
	for (int i=1; i<_N-1; i++) {
		_b(i) = _b(i) - _a(i-1)*_c(i-1)/_b(i-1); 
		_g(i) = _g(i) - _g(i-1)*_a(i-1)/_b(i-1); 
	}
}

void GenThomasSolver::backward_substitution() {
	_v(_N-1) = _g(_N-1)/_b(_N-1); 
	for (int i=_N-2; i>0; i--)  {
		_v(i) = _g(i) - _c(i)*_v(i+1)/_b(i);  
	}

}


void GenThomasSolver::solve() {
	forward_substitution(); 
	backward_substitution(); 

}
