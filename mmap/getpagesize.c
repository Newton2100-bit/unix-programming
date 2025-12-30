#include <unistd.h>
#include <stdio.h>

int
main(int argc, char **argv){
	printf("[getpagesize] My machines page size is %ld bytes.\n", getpagesize());
	printf("[sysconf] My machines page size is %ld bytes.\n", sysconf(_SC_PAGESIZE));
	return 0;
}
