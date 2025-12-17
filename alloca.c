#include <stdio.h>
#include <string.h>
#include <alloca.h>


#define NUM 5
#define SIZE (NUM * sizeof(int))

int
main(void){
	/* we are going to use alloca here
	 * i allocates memory in stack rather than
	 * the heap
	 */
	int *number;
	number = alloca(SIZE);
	memset(number, 10, SIZE);

	for(int i = 0; i < NUM; i++)
		printf("value %d.\n", number[i]);
	return 0;
}
