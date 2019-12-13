#include "xinu.h"
#include <stdlib.h>
#include "../headers/sample.hh"

float fault_prob;

float floatrand()
{
	
	return rand() / MAX_RAND;
}

/* size parameter must be in bytes */
bool bitmemerr(void * mem, size_t size) {
	
	if(floatrand() < fault_prob) {
		char * mod = (char *) mem;
		int byteindex = rand() % size;
		int bitindex = rand() % 8;
		char modbyte = mod[byteindex];
		char mask = 1 << bitindex;
		modbyte = modbyte ^ mask;
		mod[byteindex] = modbyte;
		return true;
	}
	return false;
}
