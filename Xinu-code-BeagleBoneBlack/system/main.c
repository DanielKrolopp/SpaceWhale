/*  main.c  - main */

#include <xinu.h>
#include <stdlib.h>

uint32 currtime;

process	main(void)
{
	gettime(&currtime);

	srand(currtime);

	kprintf("\nThe text segment ranges from 0x%08x to 0x%08x (Total size: %d)\n", (uint32) &text, (uint32) &etext, &etext - &text);
	kprintf("The data segment ranges from 0x%08x to 0x%08x (Total size: %d)\n", (uint32) &data, (uint32) &edata, &edata - &data);
	kprintf("The BSS  segment ranges from 0x%08x to 0x%08x (Total size: %d)\n", (uint32) &bss,  (uint32) &ebss, &ebss - &bss);
	
	kprintf("starting test...\n");
	uint32 mean_fault_frequency = 1000; // in ms (1000 / mff = faults / second)
	resume(create(rambo, INITSTK, 100, "rambo", 2, mean_fault_frequency, 'a', NULL)); 
	
	// Experiment 1
	// start_test(100, 314);

	// Experiment 2
	//start_voter_test(3, 60, 47906);
	 end_voter_test();
	// kprintf("finished test...\n");

	return OK;
}
