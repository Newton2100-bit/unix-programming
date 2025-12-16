#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void
signal_handler(int signum){
	if(signum == SIGTERM || signum == SIGINT)
		fprintf(stderr, "\rCaught signal [%02d] %s\n",signum, strsignal(signum));
	else
	{
		fprintf(stderr, "\rUnexpected  signal was recieved\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}

int
main(void){

	/*
	 * Register signal_handler as our signal handler
	 * for SIGINT.
	 */
	if (signal (SIGINT, signal_handler) == SIG_ERR) {
		fprintf (stderr, "\rCannot handle SIGINT!\n");
		exit (EXIT_FAILURE);
	}

	/*
	 * Register signal_handler as our signal handler
	 * for SIGTERM.
	 */
	
	if (signal (SIGTERM, signal_handler) == SIG_ERR) {
		fprintf (stderr, "\rCannot handle SIGTERM!\n");
		exit (EXIT_FAILURE);
	}

	/* Reset SIGPROF's behavior to the default. */

	if (signal (SIGPROF, SIG_DFL) == SIG_ERR) {
		fprintf (stderr, "\rCannot reset SIGPROF!\n");
		exit (EXIT_FAILURE);
	}

	/* Ignore SIGHUP. */

	if (signal (SIGHUP, SIG_IGN) == SIG_ERR) {
		fprintf (stderr, "\rCannot ignore SIGHUP!\n");
		exit (EXIT_FAILURE);
	}
	for (;;)
		pause ( );
	return 0;
}
