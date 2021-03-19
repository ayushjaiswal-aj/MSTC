#include <stdio.h>
#include <stdlib.h>
#include "stdcall.h"

int STDCALL sum_of_two_integers(int n1, int n2);

int main(void){
	int a=10, b=20, sum;

	sum = sum_of_two_integers(a, b);
	printf("sum = %d\n", sum);

	return (0);
}

int STDCALL sum_of_two_integers(int n1, int n2){
	return (n1+n2);
}
