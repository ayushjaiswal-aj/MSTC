#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <getopt.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd;
	char *f_name = "abc.txt";
	fd = open(f_name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if(fd < 0){
		printf("open:%s%s\n", f_name, strerror(errno));
		exit(EXIT_FAILURE);
	}

	if(close (fd) == -1){
		printf("close: %s:%s\n", f_name, strerror(errno));
		exit(EXIT_FAILURE);
	}
	exit (EXIT_SUCCESS);
}

