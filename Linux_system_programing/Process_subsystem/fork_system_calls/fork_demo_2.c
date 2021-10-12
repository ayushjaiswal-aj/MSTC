#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main(void){
	pid_t pid;
	int ret;

	pid = fork();
	if((int)pid == -1){
		fprintf(stderr, "fork: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if((int)pid == 0){
		printf("this is child, pid = %d\n", (int)getpid());
		sleep(5);
		exit(300);
	}
	else {
		printf("this is parent, pid = %d\n", (int)getpid());
		wait(&ret);
		printf("My child process is done executing with return status: %d\n", ret);
	}

	/* this line will be executed only once since child process has exit command before before reaching here */
	return (EXIT_SUCCESS);
}

