#include "../headers/sample.hh"
#include <random>
#include <ctime>

using namespace std;

float fault_prob;

float floatrand()
{
	
	static std::mt19937 rng_engine((unsigned) time(nullptr));
	static std::uniform_real_distribution<float> distribution;
	return distribution(rng_engine);
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
