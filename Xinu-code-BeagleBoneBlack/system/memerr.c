#include <xinu.h>
#include <stdlib.h>
#include "headers/sample.hh"

float fault_prob;

float floatrand()
{
	
	return (float) rand() / RAND_MAX;
}

/* size parameter must be in bytes */
bool8 bitmemerr(void * mem, int size) {
	
	if(floatrand() < fault_prob) {
		char * mod = (char *) mem;
		int byteindex = rand() % size;
		int bitindex = rand() % 8;
		char modbyte = mod[byteindex];
		char mask = 1 << bitindex;
		modbyte = modbyte ^ mask;
		mod[byteindex] = modbyte;
		return TRUE;
	}
	return FALSE;
}
