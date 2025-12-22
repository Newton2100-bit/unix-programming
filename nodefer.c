#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void
handler(int sig) {
	char msg1[] = "\rHandler start\n", msg2[] = "Handler end\n";
	write(2, msg1, sizeof(msg1));
	sleep(2);
	write(2, msg2, sizeof(msg2));
}

int
main() {
	struct sigaction sa = {0};
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);  // no extra blocked signals
				   // sa.sa_flags = 0;         // default behavior
	sigaction(SIGINT, &sa, NULL);

	for (;;) pause();
}
