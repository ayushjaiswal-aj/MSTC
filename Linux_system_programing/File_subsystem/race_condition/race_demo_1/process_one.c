#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <getopt.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd, fd_new;
	char *f_name = "abc.txt";
	fd = open(f_name, O_WRONLY);
	if(fd != -1){
		printf("open:%zu file %s already exists\n", getpid(), argv[1]);
		close(fd);
	}
	else {
		printf("Going to sleep ...\n");
		sleep (15);
		fd_new = open(f_name, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if(fd < 0){
			printf("open: %s:%s\n", f_name, strerror(errno));
			exit(EXIT_FAILURE);
		}
		printf("fd_new = %zu\n", fd_new);
	}

	printf("fd = %d\n", fd);
	if(close(fd) == -1){
		printf("close:%s:%s\n", f_name, strerror(errno));
		exit (EXIT_FAILURE);
	}
	exit (EXIT_SUCCESS);
}
