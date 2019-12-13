#include <xinu.h>
#include "headers/sample.hh"
#include "headers/pipeline.hh"

void start_test(int iters, int input) {
        
	kprintf("Processing %d iterations with input %d...\n", iters, input);
	int result = cpu_bound(iters, input);
	kprintf("Processing complete. Sending result: %d...\n", result);
	sendinit(BEAGLE161, PORT161, PORT160);
	sendmsg(result);
	kprintf("Result sent!\n");
}
