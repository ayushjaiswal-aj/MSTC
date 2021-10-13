#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(void){
	pid_t pid;
	int ret;

	static char *args[] = {"ls", "-l", "/", (char*)0};

	pid = fork();
	if((int)pid == -1){
		fprintf(stderr, "fork: %s\n", strerror(errno));
		exit(EXIT_SUCCESS);
	}

	if((int)pid == 0){
		execvp(args[0], args);
	}
	else {
		wait(&ret);
	}
	return (EXIT_SUCCESS);
}
