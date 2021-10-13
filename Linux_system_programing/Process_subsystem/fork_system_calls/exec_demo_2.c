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
		printf("child process: pid = %d\n", (int)getpid());
		execlp("ls", "ls", "-l", "/", (char*)0);
		exit(EXIT_SUCCESS);
	}
	else{
		wait(&ret);
		printf("parent process waiting for child to finish\n");
		printf("child process return status: %d\n", ret);
	}
	exit(EXIT_SUCCESS);
}
