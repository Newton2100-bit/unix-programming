#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

/* we should note that signal does not set errno
 * so it just returns SIG_ERR and that's it
 *
 * worth looking at ( sighandler_t ) 
 *
 * The pause() system call
 * it blocks and waits for unignored signals
 * returns -1 for a handled signal
 * and sets errno
 *
 * Actions inside the pause implementation
 *  > puts the process in an interruptable sleep state
 *  > calls schedule() to invoke the linux scheduler to find anorther process
 *  	to run.
 */

void 
sigint_handler(int signo){
	printf("Caught sigint <>\n");
	exit(EXIT_FAILURE);
}


int
main(void){
	if(signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		fprintf(stderr, "we couldn't install sigint handler.\n");
		exit(EXIT_FAILURE);
	}

	for(;;) pause();

	return EXIT_SUCCESS;
}
