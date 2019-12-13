#include <xinu.h>
#include <stdlib.h>
#include "headers/sample.hh"

#define HEAP_SIZE 1024

int cpu_bound(int iters, int input) {

	int heap[HEAP_SIZE];
	int i, j, k;
	kprintf("input: %d\n", input);
	for(i = 1; i < HEAP_SIZE; i++) {
		heap[i] = i * input * input;
	}
	for(k = 0; k < iters; k++) {
		for(i = 1; i < HEAP_SIZE; i++) {
			for(j = 1; j < i; j++) {
				heap[i] *= (heap[j] + 1);
			}
		}
		if(bitmemerr(&heap, HEAP_SIZE * sizeof(int))) {
			kprintf("MEMORY ERROR!\n");
		}
	}
	
	/* for(i = 0; i < HEAP_SIZE; i++)
		kprintf("[%d]", heap[i]);
	kprintf("\n"); */

	int result = heap[HEAP_SIZE - 1];
	return result;
}
