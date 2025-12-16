#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

/* we can send signals in various ways 
 * 1. to yourself
 * 2. to anorther process( you need some permissions
 * 	kill(pid_t pid, int signo)
 * 		pids go like this
 * 			>0 - the exact process with this number you provided
 * 			 0 - every process in the same group as the sending one
 * 			-1 - evry process that the process has permissions it can send to excpet (itself and the init)
 * 			<0 - process in the process group of the absolute of the value
 * 	raise(int signum)
 *
 * 	on success kill() returns 0 on error returns -1 and sets errno
 * 			EINVAL - invalid signal
 * 			EPERM - lacks permissions
 * 			ESRCH - process or process group you specified doesn't exist
 */

void 
parent_handler(int signo){
	char text[] = "In parent we received a signal\n";
	write(2, text, sizeof(text));
	_exit(EXIT_FAILURE);
}

void
child_handler(int signo){
	char text[] =  "child killed by parent\n";
	write(2, text, sizeof(text));
	_exit(EXIT_FAILURE);
}

int 
main(void){
	signal(SIGINT, parent_handler);
	pid_t pid;
	if((pid = fork()) < 0){
		fprintf(stderr, "Error creating  a child process\n");
		exit(EXIT_FAILURE);
	}

	if(pid > 0){
		sleep(1);
		switch(kill(pid, SIGINT)){
			case 0: break;
			case EPERM:
			fprintf(stderr, "no persmission to raise the signal\n");
			break;
			case ESRCH:
			fprintf(stderr, "Unknown target\n");
			break;
			default:
			fprintf(stderr, "I don't know what happenned\n");
		}

		wait(NULL);
	}else{
		if((signal(SIGINT,child_handler)) == SIG_ERR)
			fprintf(stderr, "we could not install signal handler in child\n");
		for(;;);
	}


	return 0;
}
