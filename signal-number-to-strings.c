#include <signal.h>
#include <string.h>
#include <stdio.h>

/* Like we have perror() and strerror() 
 * then 
 * in signals we are covered and we have
 * psignal() and strsignal()
 * and that's it
 */

int main(void){
	for(int i = 0;i < 20; i++)
		psignal(i ,"signal ");

	printf("\n\t\tSTRINGS REPRESENATION\n");
	for(int i = 0;i < 20; i++)
		fprintf(stdout, "\t%s\n", strsignal(i));

	return 0;
}
	

