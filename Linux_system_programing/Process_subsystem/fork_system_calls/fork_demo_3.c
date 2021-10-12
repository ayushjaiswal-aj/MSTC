#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

int main(void){
	int ret;
	pid_t pid;

	pid = fork();

	if((int)pid == -1){
		fprintf(stderr, "fork: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if((int)pid == 0){
		while(TRUE){
			printf("C: pid = %d ppid = %d\n", (int)getpid(), (int)getppid());
			sleep(1);
		}
	}
	else {
		while(TRUE){
			printf("P: pid = %d ppid = %d\n", (int)getpid(), (int)getppid());
			sleep (2);
		}
	}

	return (EXIT_SUCCESS);
}
