#include <iostream>
#include <math.h>
#include "../headers/sample.hh"

#define HEAP_SIZE 1024

using namespace std;


float cpu_bound(int iters, float input) {

	float heap[HEAP_SIZE];
	for(int i = 1; i < HEAP_SIZE; i++) {
		heap[i] = pow(i, input);
	}
	for(int k = 0; k < iters; k++) {
		for(int i = 1; i < HEAP_SIZE; i++) {
			for(int j = 1; j < i; j++) {
				heap[i] += heap[j] / i / iters;
			}
		}
		if(bitmemerr(&heap, HEAP_SIZE * sizeof(float))) {
			cout << "MEMORY ERROR!" << endl;
		}
	}
	
	float result = heap[HEAP_SIZE - 1] - (int) heap[HEAP_SIZE - 1];
	return result;
}
