#include "../headers/sample.hh"
#include <iostream>

using namespace std;

int main(int argc, char ** argv) {
	
	int iters = atoi(argv[0]);
	float input = atof(argv[1]);
	fault_prob = atof(argv[2]);
	cout << cpu_bound(iters, input) << endl;
	return 0;
}
