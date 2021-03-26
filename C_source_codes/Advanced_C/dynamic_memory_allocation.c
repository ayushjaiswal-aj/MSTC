#include<stdio.h>
#include<stdlib.h>

void* xcalloc(unsigned long int number_of_members, unsigned long int size_per_member);

void* xmalloc(unsigned long int size_in_bytes);

int main (void){
	int i;
	int* pc = NULL;
	int* pm = NULL;
	
	puts("memory allocation usigng calloc:");
	pc = (int*)xcalloc(10, sizeof(int));
	for (i=0; i<10; i++){
		printf("pc[%d]: %d\n", i, pc[i]);
	}

	puts("memory allocation using malloc:");
	pm = (int*)xmalloc(sizeof(int) * 10);
	for (i=0; i<10; i++){
		printf("pm[%d]: %d\n", i, pm[i]);
	}
	
	return(0);
}

void* xcalloc(unsigned long int number_of_members, unsigned long int size_per_member){
	void* p = NULL;
	p = calloc(number_of_members, size_per_member);
	if (p == NULL){
		fprintf(stderr, "calloc: out of memory\n");
		exit(EXIT_FAILURE);
	}

	return (p);
}

void* xmalloc(unsigned long int size_in_bytes){
	void* p = NULL;
	p = malloc(size_in_bytes);
	if (p == NULL){
		fprintf(stderr, "malloc: out of memory\n");
		exit(EXIT_FAILURE);
	}

	return (p);
}
