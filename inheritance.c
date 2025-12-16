#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signum){
	fprintf(stderr, "i am parent signal handler");
}	

int main(void){
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);

	pid_t pid  = fork();
	if (pid < 0) exit(errno);

	if(pid > 0) wait(NULL);
	if(pid == 0){
		execlp("./psignal", "newton", NULL);
	}
	fprintf(stderr, "\n\nChils took over now i am th parent\n");
	return 0;
}


