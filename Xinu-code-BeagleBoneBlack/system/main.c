/*  main.c  - main */

#include <xinu.h>

process	main(void)
{

	kprintf("text:\t0x%x -> 0x%x (%d)\n", &text, &etext, &etext - &text);
	kprintf("data:\t0x%x -> 0x%x (%d)\n", &data, &edata, &edata - &data);
	kprintf("bss:\t0x%x -> 0x%x (%d)\n", &bss, &ebss, &ebss - &bss);

	kprintf("starting test...\n");
	start_test(2, 9);
//	middle_test(3);
//	end_test(3);
	kprintf("finished test...\n");

	return OK;
}
