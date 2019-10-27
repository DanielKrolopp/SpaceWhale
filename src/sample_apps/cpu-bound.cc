#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char ** argv) {
	float iters = atof(argv[1]);
	float input = atof(argv[2]);

	float heap[1024];
	for(int i = 1; i < 1024; i++) {
		heap[i] = pow(i, input);
	}
	for(int k = 0; k < iters; k++) {
		for(int i = 1; i < 1024; i++) {
			for(int j = 1; j < i; j++) {
				heap[i] += heap[j] / i / iters;
			}
		}
	}
	
	cout << heap[1023] << endl;
	return 0;
}
