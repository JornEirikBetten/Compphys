#include "tridiagsolver.hpp"
#include "math.h"
#include <string>
#include <time.h>
 
// function f(x) in problem
vec f(vec x) {
	return 100.*exp(-10.*x); 

}
// exact solution of problem
vec u(vec x) {
	return 1-(1-exp(-10.))*x-exp(-10.*x); 
}

int main(int argc, char const *argv[]) {
	clock_t t1, t2; // initiating timer variables
	int N = atoi(argv[1]); // first argument as number of datapoints to solve for. 
	string algo = string(argv[2]);  // second argument is choice of algorithm. 
	string filename = algo + "_N_" + to_string(N) + ".csv";  // name of output file. 
	if (algo == "general") {
		GenThomasSolver mySolver; //using general thomas solver
		mySolver.init(N, f, u); // initiating problem
		t1 = clock(); // timer 
		mySolver.solve();  // solving for v
		t2 = clock(); // timer
		mySolver.calculate_error(); // calculating absolute and relative erros
		mySolver.write_to_csv(filename); // writing data to file
		}
	if (algo == "special") {
		SpecThomasSolver mySolver; // using special algorithm
		mySolver.init(N, f, u); // initiating problem
		t1 = clock(); // timer
		mySolver.solve(); // solving for v
		t2 = clock(); // timer
		mySolver.calculate_error(); // calculating absolute and relative errors
		mySolver.write_to_csv(filename); // writing data to file
	}
	double duration_seconds = ((double) (t2-t1))/ CLOCKS_PER_SEC;  // calculating time used in seconds
	std::cout << " For N =" + to_string(N) + " using the algorithm of type " + algo+ " it took "+ to_string(duration_seconds) + " seconds to run."; // printing time used and algorithm
	return 0; 

}
