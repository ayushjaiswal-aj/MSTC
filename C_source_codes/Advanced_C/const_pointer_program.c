#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int m = 10;

int *const const_ptr_non_const_int = &m;

const int* const const const_ptr_to_const_int = &m;

int main(void){

	auto int pxyz;
	register int xyz;

	int n = 20;

	printf("Before: m= %d\n", m);
	*const_ptr_non_const_int = 1000;
	printf("After: m = %d\n", m);

	int* const A = (int* const)malloc(10 * sizeof(int));

	return (0);
}
