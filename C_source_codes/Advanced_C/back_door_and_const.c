#include <stdio.h>
#include <stdlib.h>

const int gc_num = 100;

int main(void){
	const int lc_num = 1000;
	int* p = NULL;

	p = &lc_num;

	printf("Before assignment: lc_num = %d\n", lc_num);

	*p = 5000;

	printf("After assignment: lc_num = %d\n", lc_num);

	p = &gc_num;

	printf("Before assignment: gc_num = %d\n", gc_num);

	*p = 500;

	printf("After assignment: gc_num = %d\n", gc_num);

	return EXIT_SUCCESS;
}
