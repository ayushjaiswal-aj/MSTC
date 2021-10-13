#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>

int main(void){
	pid_t pid;
	int ret;

	pid = fork();
	if((int)pid == -1){
		fprintf(stderr, "fork:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if((int)pid == 0){
		printf("child process: pid: %d\n", (int)getpid());
		execl("/bin/ls", "ls", "-l", "/", (char*)0);
		exit(EXIT_SUCCESS);
	}
	else {
		wait(&ret);
		printf("parent process waits till child process executes\n");
		printf("child process return status: %d\n", ret);
	}
	return (EXIT_SUCCESS);
}
