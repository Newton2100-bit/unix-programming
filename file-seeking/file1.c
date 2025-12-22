#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


char filename[] = "sample-file.txt";
char fortune[50];
FILE *input;
int input_fd, output_fd;

void
copy(void){
	int n, total_bytes = 0;
	while(( n = read(input_fd, fortune, sizeof(fortune))) > 0){
		total_bytes += n;
		write(output_fd, fortune, n);

		if((total_bytes % 10) == 0){
			lseek(output_fd, 4096, 2);
			n = write(output_fd, "[break]",strlen("[break]"));
			total_bytes += n;
		}
	}

	fprintf(stderr, "%d bytes copied to %s\n", total_bytes, filename);
}


int
main(void){
	if((output_fd = creat(filename, 0644)) == -1){
		fprintf(stderr, "Error creating file [%s]\n", filename);
		exit(EXIT_FAILURE);
	}

	input = popen("fortune", "r");
	if(input == NULL){
		fprintf(stderr, "Error runnig fortune command\n");
		exit(EXIT_FAILURE);
	}
	input_fd = fileno(input);
	copy();

	fclose(input);
	close(input_fd);
	close(output_fd);
	return 0;
}
