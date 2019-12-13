#include <xinu.h>
#include <stdlib.h>
#include "headers/sample.hh"

#define WORKSPACE_SIZE 1024

int workspace[WORKSPACE_SIZE];

int cpu_bound(int iters, int input) {

	int i, j, k;
	for(i = 1; i < WORKSPACE_SIZE; i++) {
		workspace[i] = i * input * input;
	}
	for(k = 0; k < iters; k++) {
		for(i = 1; i < WORKSPACE_SIZE; i++) {
			for(j = 1; j < i; j++) {
				workspace[i] *= (workspace[j] + 1);
			}
		}
	}
	
	/* for(i = 0; i < HEAP_SIZE; i++)
		kprintf("[%d]", heap[i]);
	kprintf("\n"); */

	int result = workspace[WORKSPACE_SIZE - 1];
	return result;
}
