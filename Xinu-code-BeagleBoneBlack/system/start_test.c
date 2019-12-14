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
	print_errors();
}

void start_voter_test(int rounds, int iters, int input) {
        
	kprintf("Processing %d rounds of %d iterations with input %d...\n", rounds, iters, input);
	uint32 wait_time = ms;
	int result1 = cpu_bound(iters, input);
	kprintf("Round 1 complete. Intermediate result: %d\n", result1);
	int result2 = cpu_bound(iters, result1);
	kprintf("Round 2 complete. Intermediate result: %d\n", result2);
	int result3 = cpu_bound(iters, result2);
	uint32 compute_time = ms - wait_time;
	kprintf("Round 3 complete. Sending result: %d...\n", result3);
	sendinit(BEAGLE163, PORT163, PORT160);
	sendmsg(result3);
	kprintf("Result sent!\n");
	kprintf("Wait time: %d, compute time: %d\n", wait_time, compute_time);
	print_errors();
}
