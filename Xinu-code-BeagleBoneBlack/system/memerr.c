#include <xinu.h>
#include <stdlib.h>
#include "headers/sample.hh"

int bssflips  = 0;
int dataflips = 0;
int textflips = 0;
int otherflips = 0;

float fault_prob;

float floatrand()
{
	return (float) rand() / RAND_MAX;
}

int memerr(char where){
	uint32 corruptstart;
	uint32 corruptstop;

	switch(where){
		// 'BSS'
		case 'b':
			corruptstart = (uint32) &bss;
			corruptstop = (uint32) &ebss;
			break;
		// 'Text'
		case 't':
			corruptstart = (uint32) &text;
			corruptstop = (uint32) &etext;
			break;
		// 'Data'
		case 'd':
			corruptstart = (uint32) &data;
			corruptstop = (uint32) &edata;
			break;
		// 'Many' (BSS/Text/Data)
		case 'm':
			corruptstart = (uint32) &text;
			corruptstop = (uint32) &ebss;
			break;
		// 'All' (All possible memory)
		case 'a':
			corruptstart = (uint32) &text;
			corruptstop = (uint32) &end;
			break;
		default:
			return -1;
			break;
	}

	// Pick a byte
	uint32 byteindex = rand() % (corruptstop - corruptstart);

	// Find out where the byte is and increment the appropiate counter
	if( corruptstart + byteindex < (uint32) &etext ){
		textflips++;
	}else if( corruptstart + byteindex < (uint32) &edata ){
		dataflips++;
	}else if( corruptstart + byteindex < (uint32) &ebss ){
		bssflips++;
	}else{
		otherflips++;
	}
	
	
	unsigned short bitindex = rand() % 8;


	char * mod  = (char*) corruptstart;
	char modbyte = mod[byteindex];
	char mask = 1 << bitindex;
	modbyte = modbyte ^ mask;
	mod[byteindex] = modbyte;

	return 0;
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

void print_errors() {
	kprintf("TEXT  flips: %d\n", textflips);
	kprintf("DATA  flips: %d\n", dataflips);
	kprintf("BSS   flips: %d\n", bssflips);
	kprintf("OTHER flips: %d\n", otherflips);
}
