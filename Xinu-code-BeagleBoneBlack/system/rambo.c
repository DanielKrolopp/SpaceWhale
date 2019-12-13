#include <xinu.h>
#include <stdlib.h>

process rambo(int mean_sleep, char type) {
	
	while(TRUE) {
		int sleep_time = rand() % (mean_sleep * 2);
		// kprintf("Rambo is sleeping for %d ms!\n", sleep_time);
		sleepms(sleep_time);
		memerr(type);
	}
}
