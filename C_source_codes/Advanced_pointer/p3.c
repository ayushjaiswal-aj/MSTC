/* Declare a pointer of array of 5 struct A */

#include <stdio.h>
#include <stdlib.h>

struct A{
	int a;
	char b;
	float c;
};

struct A (*pA)[5];

struct A arr[5] = {
			{10, 'a', 3.14f},
			{20, 'b', 4.15f},
			{30, 'c', 5.16f},
			{40, 'd', 6.17f},
			{50, 'e', 7.18f}
		};

int main(void){
	int i;
	int copy_a;
	char copy_b;
	float copy_c;

	pA = &arr;

	for (i=0; i<5; i++){
		copy_a = (*pA)[i].a;
		copy_b = (*pA)[i].b;
		copy_c = (*pA)[i].c;
		printf("index = %d\ncopy_a = %d\ncopy_b = %c\ncopy_c = %f\n", i, copy_a, copy_b, copy_c);
		puts("------------------------------------------------------------------------------");
	}

	return 0;
}
