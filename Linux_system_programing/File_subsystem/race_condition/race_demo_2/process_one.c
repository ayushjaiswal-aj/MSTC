#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void *xcalloc(int, int);
void print_usage(void);
void print_version(void);

#define STR_EQ 0
#define LONG_OPT 0
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]){
	int ret, i;
	int len, wb;
	int name_flag = FALSE, append_flag = FALSE;
	int open_flag;
	int fd;
	off_t off;
	char *f_name;

	struct option opts[] = {
		{"help", no_argument, 0, 0},
		{"version", no_argument, 0, 0},
		{"name", required_argument, 0, 'n'},
		{"append", no_argument, 0, 'a'},
		{0,0,0,0}
	};

	if(argc == 1){
		print_usage();
		exit(EXIT_FAILURE);
	}
	while ((ret == getopt_long(argc, argv, "hvn:a", opts, &i)) != -1){
		switch (ret){
			case 'h':
				print_usage();
				exit(EXIT_SUCCESS);
			case 'v':
				print_version();
				exit (EXIT_SUCCESS);
			case 'n':
				name_flag = TRUE;
				f_name = optarg;
				break;
			case 'a':
				append_flag = TRUE;
				break;
			default:
				print_usage();
				exit (EXIT_FAILURE);
		}
	}

	if(name_flag == FALSE){
		print_usage();
		exit(EXIT_FAILURE);	
	}

	if(append_flag == TRUE){
		open_flag = O_RDWR | O_APPEND;
	}

	fd = open(f_name, open_flag);
	if(fd<0){
		printf("open:%s:%s\n", f_name, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("going to write at offset = %d\n", (int)off);
	

	sleep (10);
	len = strlen ("hello, world!");
	wb = write(fd, "hello, world!", len);
	if(wb != len){
		printf("write:%s:%s\n", f_name, strerror(errno));
		exit(EXIT_FAILURE);
	}

	if(close(fd) == -1){
		printf("close:%s:%s\n", f_name, strerror(errno));
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

void print_usage(){
	printf("	[options]\n--help:prints help\n--version:prints version\n");
}

void print_version(){
	printf("0.1\n");
}

void *xalloc(int nr_elements, int size_per_element){
	void *ptr = NULL;
	ptr = calloc(nr_elements, size_per_element);
	if(ptr == NULL){
		fprintf(stderr, "xcalloc:fatal:out of memory\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
