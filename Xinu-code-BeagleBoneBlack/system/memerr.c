#include <xinu.h>
#include <stdlib.h>
#include "headers/sample.hh"

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
			kprintf("Flipping bit in BSS\n");
			corruptstart = (uint32) &bss;
			corruptstop = (uint32) &ebss;
			break;
		// 'Text'
		case 't':
			kprintf("Flipping bit in text\n");
			corruptstart = (uint32) &text;
			corruptstop = (uint32) &etext;
			break;
		// 'Data'
		case 'd':
			kprintf("Flipping bit in data\n");
			corruptstart = (uint32) &data;
			corruptstop = (uint32) &edata;
			break;
		// 'Many' (BSS/Text/Data)
		case 'm':
			kprintf("Flipping a bit in BSS, text, or data\n");
			corruptstart = (uint32) &text;
			corruptstop = (uint32) &ebss;
		// 'All' (All possible memory)
		case 'a':
			kprintf("Flipping a bit anywhere in memory\n");
			corruptstart = (uint32) &text;
			corruptstop = (uint32) &end;
		default:
			kprintf("Invalid corruption section requested\n");
			return -1;
			break;
	}

	// Pick a byte
	//uint32 currtime = 0;
	//gettime(&currtime);
	//srand(currtime);
	uint32 byteindex = rand() % (corruptstop - corruptstart);
	kprintf("Byte to corrupt: 0x%08x\n", byteindex);

	unsigned short bitindex = rand() % 8;
	kprintf("Bit to corrupt: %d\n", bitindex);


	char * mod  = (char*) corruptstart;
	char modbyte = mod[byteindex];
	kprintf("Byte before modification:\t0x%08x\n", modbyte);
	char mask = 1 << bitindex;
	modbyte = modbyte ^ mask;
	kprintf("Byte after modification:\t0x%08x\n", modbyte);
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
