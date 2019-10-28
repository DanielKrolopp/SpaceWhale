#include <iostream>
#include <math.h>

using namespace std;

float cpu_bound(int iters, float input) {

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
	
	return heap[1023];
}
