#include <signal.h>
#include <unistd.h>
#include <stdio.h>
int count = 0;

int main(void){
	signal(SIGINT, SIG_IGN);

	for(int i = 0; i < 20; i++){
		count++;
		//psignal(i, "[ first message ]");
		sleep(2);
		fprintf(stderr,"\r%d", count);
	}

	return 0;
}

