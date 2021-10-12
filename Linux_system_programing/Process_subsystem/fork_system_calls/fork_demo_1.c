#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
	int ret;
	pid_t pid;

	pid = fork();

	if((int)pid == -1){
		fprintf(stderr, "fork: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if((int)pid == 0){
		printf("child process pid = %d\n", (int)getpid());
	}
	else {
		printf("parent process pid  = %d\n", (int)getpid());
	}

	printf("comman area\n");
	return (EXIT_SUCCESS);
}
