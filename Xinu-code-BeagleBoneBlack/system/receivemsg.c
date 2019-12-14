#include "headers/sample.hh"
#include <xinu.h>
#include <stdlib.h>

uid32 recv_slot;
uid32 recv_slots[3];

int received;

void receiveinit(char * ip_text, uint16 remote_port, uint16 local_port, int idx) {
	uint32 ip = 0;
	dot2ip(ip_text, &ip);
	recv_slots[idx] = udp_register(ip, remote_port, local_port);
}

int receivemsg(int idx) {
	uint32 remote_ip = 0;
	uint16 remote_port = 0;
	char buffer[16] = {0}; 
    
	int len = udp_recvaddr(recv_slots[idx], &remote_ip, &remote_port, buffer, 16, 90 * 1000);
	received = atoi(buffer);
	return atoi(buffer);
}
