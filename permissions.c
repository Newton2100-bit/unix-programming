/* NOTE
 * for you to be able to send a signal to any process in the system
 * you must have CAP_KILL capabilities(normaly for the root)
 * ortherwise you will be allowed only to send to process that have the same UID
 *  or EUID 
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void){
	/* nothing to write for now but 
	 * to note where one can send and not send signals
	 *
	 * The error associated with these permissions is 
	 *  EPERM which is set to errno once it occurs
	 *  
	 *  THOUGH there is one exceptin to these rules
	 *  the signal SIGCONT can be sent anywhere by anybody
	 *
	 *  FINALLY
	 *  we should not that signal number 0 is the null signal 
	 *  mostly used to test wheather the sender has permissions to do so
	 */
	return 0;
}

