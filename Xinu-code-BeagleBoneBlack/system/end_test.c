#include <xinu.h>
#include "headers/sample.hh"
#include "headers/pipeline.hh"

void end_test(int iters) {
        
	receiveinit(BEAGLE161, PORT161, PORT162);
	kprintf("Waiting on input...\n");
	int input = receivemsg();
	kprintf("Received! Processing %d iterations with input %d...\n", iters, input);
	int result = cpu_bound(iters, input);
	kprintf("Processing complete. Final result: %d.\n", result);
}
