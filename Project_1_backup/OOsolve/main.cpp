#include "tridiagsolver.hpp"
#include "math.h"
#include <string>
#include <time.h>


vec f(vec x) {
	return 100.*exp(-10.*x); 

}
vec u(vec x) {
	return 1-(1-exp(-10.))*x-exp(-10.*x); 
}

int main(int argc, char const *argv[]) {
	clock_t t1, t2;
	int N = atoi(argv[1]);
	string algo = string(argv[2]); 
	string filename = algo + "_N_" + to_string(N) + ".csv"; 
	if (algo == "general") {
		GenThomasSolver mySolver; 
		mySolver.init(N, f, u); 
		t1 = clock();
		mySolver.solve(); 
		t2 = clock();
		mySolver.calculate_error(); 
		mySolver.write_to_csv(filename); 
		}
	if (algo == "special") {
		SpecThomasSolver mySolver; 
		mySolver.init(N, f, u); 
		t1 = clock();
		mySolver.solve(); 
		t2 = clock();
		mySolver.calculate_error(); 
		mySolver.write_to_csv(filename);
	}
	double duration_seconds = ((double) (t2-t1))/ CLOCKS_PER_SEC; 
	std::cout << " For N =" + to_string(N) + " using the algorithm of type " + algo+ " it took "+ to_string(duration_seconds) + " seconds to run."; 
	return 0; 

}
