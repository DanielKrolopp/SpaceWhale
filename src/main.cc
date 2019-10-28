#include <iostream>
#include "headers/sample.h"

int main(int argc, char ** argv) {
        
	int iters = atoi(argv[1]);
	float input = atof(argv[2]);
	cout << cpu_bound(iters, input) << endl;
	return 0;
}
