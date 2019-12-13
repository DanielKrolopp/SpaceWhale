#include "headers/sample.hh"
#include <xinu.h>
#include <stdlib.h>

uid32 recv_slot;
int received;

void receiveinit(char * ip_text, uint16 remote_port, uint16 local_port) {
	uint32 ip = 0;
	dot2ip(ip_text, &ip);
	recv_slot = udp_register(ip, remote_port, local_port);
	kprintf("receive slot: %d\n", recv_slot);
	// kprintf("receive ip: %s (%x) : %d\n", ip_text, ip, local_port);
}

int receivemsg() {
	uint32 remote_ip = 0;
	uint16 remote_port = 0;
	char buffer[16] = {0}; 
    
	udp_recvaddr(recv_slot, &remote_ip, &remote_port, buffer, 16, 90 * 1000);
	received = atoi(buffer);
	return atoi(buffer);
}
