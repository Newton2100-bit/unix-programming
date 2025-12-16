#include <stdio.h>
#include <string.h>

int main(void){
	for(int i = 0; i < 20; i++)
		printf("[%02d] %s\n", i, strsignal(i));

	return 0;
}

