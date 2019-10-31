#include "../headers/sample.hh"

#include <sys/socket.h> 
#include <iostream>
#include <stdlib.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <string.h>

#define PORT 9099

using namespace std;

int sock = 0; 
struct sockaddr_in serv_addr; 

void sendinit(char * ip) {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
    	cout << "Error creating socket" << endl;
	} 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) { 
        cout << "Error connecting" << endl;
    } 
   
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) { 
        cout << "Error connecting" << endl;
    } 
}

void sendmsg(float message) {
    
	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%f", message);
	send(sock, buffer, sizeof(buffer), 0); 
}
