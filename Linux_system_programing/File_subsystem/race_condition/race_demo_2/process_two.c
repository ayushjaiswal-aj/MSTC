#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <getopt.h>

void* xcalloc(int nr_elements, int size_per_elements);
void print_usage(void);
void print_version(void);

#define STR_EQ 0
#define LONG_OPT 0
#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 32

char buffer[BUFFER_SIZE];

int main(int argc, char *argv[]){
	int ret, i;
	int len, wb;
	int name_flag = FALSE;
	int fd;
	off_t off;
	char *f_name;

	struct option opts[] = {
		{"help", no_argument, 0, 0},
		{"version", no_argument, 0, 0},
		{"name", required_argument, 0, 'n'},
		{0, 0, 0, 0}
	};
	
	if(argc == 1){
		print_usage();
		exit(EXIT_FAILURE);
	}

	while((ret = getopt_long(argc, argv, "hvn:", opts, &i))!= -1){
		switch(ret){
			case 'h':
				print_usage();
				exit(EXIT_SUCCESS);
			case 'v':
				print_version();
				exit(EXIT_SUCCESS);
			case 'n':
				name_flag = TRUE;
				f_name = optarg;
				break;
			defalut:
				print_usage();
				exit(EXIT_FAILURE);
		}
	}
	fd = open(f_name, O_RDWR | O_APPEND);
	if(fd < 0){
		print_usage();
		exit(EXIT_FAILURE);
	}

	sleep (5);
	memset (buffer, 'A', BUFFER_SIZE);
	wb = write(fd, buffer, BUFFER_SIZE);
	if(wb != BUFFER_SIZE){
		printf("write:%s:%s\n", f_name, strerror(errno));
		exit(EXIT_FAILURE);
	}

	if(close (fd) == -1){
		printf("close:%s:%s\n", f_name, strerror(errno));
		exit(EXIT_FAILURE);
	}

	exit (EXIT_SUCCESS);
}

void print_usage(void){
	printf("	[options]\n--help:prints help\n--version: prints version\n");
}

void print_version(){
	printf("0.1\n");
}

void *xcalloc(int nr_elements, int size_per_element){
	void *ptr;
	ptr = calloc(nr_elements, size_per_element);
	if(ptr == NULL){
		fprintf(stderr, "xcalloc:fatal:out of memory\n");
		exit (EXIT_FAILURE);
	}

	return (ptr);
}
