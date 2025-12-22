#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void
handler(int signo, siginfo_t *info, void *context){
	int payload;
	if(info->si_code == SI_QUEUE)
		payload = info->si_int;
	else
		return;

	write(2, "we had the payload as ", 20);
}

int
main(void){
	struct sigaction sa;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGHUP, &sa, NULL);

	union sigval payload;
	payload.sival_int = rand();
	sigqueue(getpid(), SIGHUP, payload);

	for(;;) pause();
	return 0;
}
