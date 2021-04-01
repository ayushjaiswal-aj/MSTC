#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void get_integer_instance(int** pp);

int main(void){
	int* p = NULL;

	get_integer_instance(&p);
	printf("address of (&p) = %p\n", &p);
	printf("address in (p) = %p\n", p);
	printf("address of (&p) = %p\n", &p);
	printf("address in (p) = %p\n", p);

	*p = 700;
	
	printf("*p = %d\n", *p);
	free (p);
	p = NULL;

	return (EXIT_SUCCESS);
}

void get_integer_instance(int** pp){
	*pp = malloc(sizeof(int));
} 
