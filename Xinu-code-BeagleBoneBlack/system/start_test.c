#include <xinu.h>
#include "headers/sample.hh"
#include "headers/pipeline.hh"

void start_test(int iters, int input) {
        
	kprintf("Processing %d iterations with input %d...\n", iters, input);
	uint32 wait_time = ms;
	int result = cpu_bound(iters, input);
	uint32 compute_time = ms - wait_time;
	kprintf("Processing complete. Sending result: %d...\n", result);
	sendinit(BEAGLE161, PORT161, PORT160);
	sendmsg(result);
	kprintf("Result sent!\n");
	kprintf("Wait time: %d, compute time: %d\n", wait_time, compute_time);
}
