#include <iostream>
#include "headers/sample.hh"
#include "headers/pipeline.hh"

using namespace std;

int main(int argc, char ** argv) {
        
	int iters = atoi(argv[1]);
	receiveinit();
	cout << "Waiting on input..." << endl;
	float input = receivemsg();
	cout << "Received! Processing " << iters << " iterations with input " << input << "..." <<endl;
	float result = cpu_bound(iters, input);
	cout << "Processing complete. Final result: " << result << "." << endl;
	return 0;
}
