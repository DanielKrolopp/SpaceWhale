/*  main.c  - main */

#include <xinu.h>
#include <stdlib.h>

process	main(void)
{
	uint32 currtime = 0;
	gettime(&currtime);

	srand(currtime);

	kprintf("The current time is: %d\n", currtime);

	kprintf("A set of random numbers between 0 and 9: {");
	int i;
	for(i = 0; i < 25; i++){
		int randnum = rand();
		kprintf("%d", randnum % 10 );
		if( i != 24 )
			kprintf(", ");
	}
	kprintf("}\n");

	kprintf("\nThe text segment ranges from 0x%08x to 0x%08x (Total size: %d)\n", (uint32) &text, (uint32) &etext, &etext - &text);
	kprintf("The data segment ranges from 0x%08x to 0x%08x (Total size: %d)\n", (uint32) &data, (uint32) &edata, &edata - &data);
	kprintf("The BSS  segment ranges from 0x%08x to 0x%08x (Total size: %d)\n", (uint32) &bss,  (uint32) &ebss, &ebss - &bss);

	kprintf("starting test...\n");
	memerr('t');
	memerr('t');
//	start_test(2, 9);
//	middle_test(3);
//	end_test(3);
	kprintf("finished test...\n");

	return OK;
}
