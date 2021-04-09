/* Declare a pointer to function accepting two ints returing an int */

#include <stdio.h>
#include <stdlib.h>

int my_add(int n1, int n2);

int main(void){
	int (*pfn)(int, int) = NULL;
	int ret;

	pfn = my_add;
	ret = pfn(100, 200);
	printf("ret = %d\n", ret);

	return  (0);
}

int my_add(int n1, int n2){
	int sum;
	sum = n1+n2;
	return (sum);
}
