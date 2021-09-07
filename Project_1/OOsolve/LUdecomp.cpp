#include <armadillo>
#include <iostream>

using namespace arma; 
using namespace std; 


int main(int argc, char const *argv[]) {
	int N = atoi(argv[1]); 
	mat A = zeros(N,N); 
	cout << A; 
	 
	for (int j=0; j<N; j++) {
		A(j, j) = (double) 2.; 
		 
	}
	for (int i=0; i<N-1; i++) {
		A(i, i+1) = (double) -1.; 
		A(i+1, i) = (double) -1.; 
	}	
	
	cout << A; 
	return 0; 
}
