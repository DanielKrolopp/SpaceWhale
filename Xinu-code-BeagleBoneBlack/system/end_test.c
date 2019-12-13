#include <xinu.h>
#include "headers/sample.hh"
#include "headers/pipeline.hh"

void end_test(int iters) {
        
	receiveinit(BEAGLE161, PORT161, PORT162);
	kprintf("Waiting on input...\n");
	int input = receivemsg();
	kprintf("Received! Processing %d iterations with input %d...\n", iters, input);
	uint32 wait_time = ms;
	int result = cpu_bound(iters, input);
	uint32 compute_time = ms - wait_time;
	kprintf("Processing complete. Final result: %d.\n", result);
	kprintf("Wait time: %d, compute time: %d\n", wait_time, compute_time);
	print_errors();
}
