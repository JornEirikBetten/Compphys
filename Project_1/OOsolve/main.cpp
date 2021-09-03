#include "tridiagsolver.hpp"
#include "math.h"
#include <string>
using namespace arma; 
using namespace std; 


vec f(vec x) {
	return 100.*exp(-10.*x); 

}

int main(int argc, char const *argv[]) {
	int N = atoi(argv[1]);
	string filename = string(argv[2]); 
	GenThomasSolver mySolver; 
	mySolver.init(N, f); 
	mySolver.solve(); 
	mySolver.write_to_csv(filename); 

	return 0; 

}
