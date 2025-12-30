#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>

#define ERR(msg) do{\
	perror(msg);\
	return EXIT_FAILURE;\
}while(0);


int
main(int argc, char **argv){
	int mysocket; 
	int domain;
	int type;

	domain  = AF_INET; /* AF_INET == PF_INET && PF_INET6 == AF_INET6 */
	type  = SOCK_STREAM;

	/* There is no need to set protocol unless using raw sockets */

	if((mysocket = socket(domain , type, 0)) < 0)
		ERR("unable to open socket");

	printf("socket with fd  %d opened\n", mysocket);
	return 0;
}
