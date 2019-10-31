#include <iostream>
#include "headers/sample.hh"
#include "headers/pipeline.hh"

using namespace std;

int main(int argc, char ** argv) {
        
	int iters = atoi(argv[1]);
	float input = atof(argv[2]);
	char * ip = argv[3];
	cout << "Processing " << iters << " iterations with input " << input << "..." <<endl;
	float result = cpu_bound(iters, input);
	cout << "Processing complete. Sending result: " << result << "..." << endl;
	sendinit(ip);	
	sendmsg(result);
	cout << "Result sent!" << endl;
	return 0;
}
