#include<stdio.h>
#include<stdlib.h>

int main(void){
	int A[5] = {10, 20, 30, 40, 50};
	int (*ptr_to_arr)[];
	int *ptr;

	ptr_to_arr = A;
	ptr = A;

	printf("ptr_to_arr = %p\n", ptr_to_arr);
	printf("ptr = %p\n", ptr);

	printf("sizeof(ptr_to_arr) = %d\n", sizeof(ptr_to_arr));
	printf("sizeof(ptr) = %d\n", sizeof(ptr));
}

