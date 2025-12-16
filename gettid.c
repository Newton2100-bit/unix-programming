#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

int main(void){
	printf("The thread id is %d and pid %d.\n", gettid(), getpid());
	return 0;
}
