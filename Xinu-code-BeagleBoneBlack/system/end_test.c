#include <xinu.h>
#include "headers/sample.hh"
#include "headers/pipeline.hh"

sid32 vote_lock;
int votes[3];
int vote_idx;

/*void end_test(int iters) {
        
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
}*/

process receiver(int idx) {
	int vote = receivemsg(idx);
	wait(vote_lock);
	votes[vote_idx++] = vote;
	kprintf("Received a vote for %d. %d/3 votes!\n", vote, vote_idx);
	if(vote_idx == 3) {
		kprintf("Votes are in! (%d) (%d) (%d)\n", votes[0], votes[1], votes[2]);
		print_errors();
		kprintf("finished test...");
	}
	signal(vote_lock);
	return OK;
}

void end_voter_test() {
    vote_lock = semcreate(1);
	vote_idx = 0;
	receiveinit(BEAGLE160, PORT160, PORT163, 0);
	receiveinit(BEAGLE161, PORT161, PORT163, 1);
	receiveinit(BEAGLE162, PORT162, PORT163, 2);
	kprintf("Waiting on input...\n");
	int i;
	for(i = 0; i < 3; i++)
		resume(create(receiver, INITSTK, 80, "receiver", 1, i, NULL));
}
