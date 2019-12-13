#include <xinu.h>
#include "headers/sample.hh"
#include "headers/pipeline.hh"

void middle_test(int iters) {
    
	receiveinit(BEAGLE160, PORT160, PORT161);
	kprintf("Waiting on input...\n");
	int input = receivemsg();
	kprintf("Received! %d Processing %d iterations with input %d...\n", received, iters, input);
	int result = cpu_bound(iters, input);
	kprintf("Processing complete. Sending result: %d...\n", result);
	sendinit(BEAGLE162, PORT162, PORT161);	
	sendmsg(result);
	kprintf("Result sent!\n");
}
