#include "tridiagsolver.hpp"


// Initiating problem, v is what we want to solve for, a is subdiagonal, b is diagonal, c is superdiagonal
void GenThomasSolver::init(int N, vec f(vec x), vec u(vec x)) {
	initialize(N, f, u); //inheriting initialize from TriDiagSolver 
	_a = vec(_N).fill(-1.); 
	_b = vec(_N).fill(2.); 
	_c = vec(_N).fill(-1.); 
	_v = vec(_N).fill(0.); 
}

// Forward substitution in general case
void GenThomasSolver::forward_substitution() {
	for (int i=1; i<=_N-1; i++) {
		_b(i) = _b(i) - _a(i-1)*_c(i-1)/_b(i-1); 
		_g(i) = _g(i) - _g(i-1)*_a(i-1)/_b(i-1); 
	}
}
// Backward substitution in general case
void GenThomasSolver::backward_substitution() {
	_v(_N-1) = _g(_N-1)/_b(_N-1); 
	for (int i=_N-2; i>=0; i--)  {
		_v(i) = (_g(i) - _c(i)*_v(i+1))/_b(i);  
	}

}

// Solving for v, first forward then backward substitution
void GenThomasSolver::solve() {
	forward_substitution(); 
	backward_substitution(); 

}

// Initiating problem. Precalculating tilde(b) 
void SpecThomasSolver::init(int N, vec f(vec x), vec u(vec x)) {

	initialize(N, f, u);  
	_b = vec(_N); 
	_v = vec(_N).fill(0.); 
	for (int i=0; i<N; i++) {
		_b(i) = 2.-(double) i/((double) i+1.); 
	}
}
// Forward substitution in special case
void SpecThomasSolver::forward_substitution() {
	for (int i=1; i<_N; i++) {
		_g(i) = _g(i) + _g(i-1)/_b(i-1); 
	}
}

// Backward substitution in special case
void SpecThomasSolver::backward_substitution() {
	_v(_N-1) = _g(_N-1)/_b(_N-1); 
	for (int i=_N-2; i>=0; i--) {
		_v(i) = (_g(i) + _v(i+1))/_b(i); 
	}

}
// Solving for v, first forward then backward substitution
void SpecThomasSolver::solve() {
	forward_substitution(); 
	backward_substitution(); 
	
}
