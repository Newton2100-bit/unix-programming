#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* A simple analogous signal handler that pes with the signl() system call */
void 
handler(int signo){
	char msg[] = "handled signal\n";
	write(2, msg, sizeof(msg));
}

/* A simple sigaction handler that is very strong and embrassing */
void action_handler(int signo, siginfo_t *info, void *uncontext){
	char msg[] = "this is our modern handler be care to be soo strong";
	write(2, msg, sizeof(msg));
}

int
main(void){
	for(int i = 0; i < 3; i++)
		signal(i, handler);


	sigset_t set;
	sigemptyset(&set);

	for(int i =2; i < 5; i++)
		sigaddset(&set, i);

	raise(2);

	sigprocmask(SIG_BLOCK, &set, NULL);

	pid_t pid = getpid();
	char command[70];
	sprintf(command, "cat /proc/%d/status", pid);
	system(command);

	sigprocmask(SIG_UNBLOCK, &set, NULL);
	return 0;
}
