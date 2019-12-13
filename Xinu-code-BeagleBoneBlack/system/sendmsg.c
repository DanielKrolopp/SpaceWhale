#include <xinu.h>
#include "headers/sample.hh"

uid32 send_slot;

void sendinit(char * ip_text, uint16 remote_port, uint16 local_port) {
	uint32 ip = 0;
	dot2ip(ip_text, &ip);
	send_slot = udp_register(ip, remote_port, local_port);
	if(send_slot == SYSERR)
		kprintf("ERROR REGISTERING SENDINIT!\n");
	// kprintf("Send info: dst: %s (%x) : %d\n", ip_text, ip, remote_port);
}

void sendmsg(int message) {
	char buf[16];
	sprintf(buf, "%d", message);
	kprintf("Sending %s\n", buf);
    udp_send(send_slot, buf, 16);
}
