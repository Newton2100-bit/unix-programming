#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/* In the code below
 * we are handling signal **SIGCHILD** but,
 * we are telling the kernel one thing
 * once the change of state of child is termination
 * the clean up the pcb ( ensuring no zombies do exist)
 */

void 
handler(int signo){
	char msg[] = "A child has exited somewhere and cleaned immediately.\n";
	write(2, msg, sizeof(msg));
}


int 
main(void) {
	struct sigaction sa;

	sa.sa_handler = handler; /* The traditional signal handler by signal() */
	sa.sa_flags = SA_NOCLDWAIT | SA_RESTART;
	sigemptyset(&sa.sa_mask); /* we don't want o block anysignals while handling SIGCHILD */

	sigaction(SIGCHLD, &sa, NULL);

	if (fork() == 0) {
		sleep(2);
		_exit(0);
	}

	sleep(3);

	return 0;
}
