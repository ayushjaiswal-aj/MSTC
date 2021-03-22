#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>

#define INVALID_FILE_DESCRIPTOR		-1
#define PLACEHOLDER_OFFSET_VALUE	0
#define PAGE_SIZE			4096

int main(void){
	size_t alloc_length = PAGE_SIZE;
	void* addr = NULL;
	char* arr_block = NULL;
	int prot_bits = PROT_READ | PROT_WRITE;
	int flag = MAP_ANONYMOUS | MAP_PRIVATE;
	char initializer = 'A';
	int i;
	int sys_ret;

	addr = mmap(NULL, alloc_length, prot_bits, flag, INVALID_FILE_DESCRIPTOR, PLACEHOLDER_OFFSET_VALUE);
	
	if (addr == NULL){
		fprintf(stderr, "mmap: failed to map memory: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	arr_block = (char*)addr;
	memset(arr_block, initializer, alloc_length);
	
	for (i=0; i<alloc_length; i++){
		printf("byte number %d: %c\n", i+1, arr_block[i]);
	}

	sys_ret = munmap(addr, alloc_length);
	if (sys_ret == -1){
		fprintf(stderr, "munmap: failed to unmap memory: %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	exit (EXIT_SUCCESS);
}
