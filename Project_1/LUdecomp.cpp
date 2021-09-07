#include <armadillo>
#include <iostream>

using namespace arma; 
using namespace std; 

vec f(vec x) {
	return 100.*exp(-10.*x);
}

int main(int argc, char const *argv[]) {
	int N = atoi(argv[1]); 
	mat A = zeros(N,N);  
	// Initiating A
	for (int j=0; j<N; j++) {
		A(j, j) = (double) 2.; 
		 
	}
	for (int i=0; i<N-1; i++) {
		A(i, i+1) = (double) -1.; 
		A(i+1, i) = (double) -1.; 
	}	
	cout << A; 
	double dx = 1.0/(N+1); 
	mat P, L, U; 
	lu(L, U, P, A); // LU-decomposing A into PLU, where P is a permutation matrix
	vec b = vec(N); 
	vec x = linspace(dx, 1-dx, N);
	vec v = vec(N); 
	// initiating b, as in Av=b
	b = dx*dx*f(x); 
	v = solve(trimatu(U), solve(trimatl(L), P*b)); //does not work
	cout << v; 
	return 0; 
}
