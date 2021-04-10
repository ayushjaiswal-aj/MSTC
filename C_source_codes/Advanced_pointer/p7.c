/*
Declare an array 5 of pointers to function acceptingtwo integers and
returning an integer

S1: array 5 of
	arr[5]

S2: array 5 of pointer 
	*arr[5]

S3: array 5 of pointer to function
	(*arr[5]) ()

S4: array 5 of pointer to function accepting two ints and
	returning an int

	int (*arr[5]) (int, int)

*/

#include <stdio.h>
#include <stdlib.h>

int cpa_add(int, int);
int cpa_sub(int, int);
int cpa_mul(int, int);
int cpa_div(int, int);
int cpa_mod(int, int);

int main(void){
	int (*arr[5]) (int, int);
	int a = 10, b = 3;
	int i;
	int ret;

	arr[0] = cpa_add;
	arr[1] = cpa_sub;
	arr[2] = cpa_mul;
	arr[3] = cpa_div;
	arr[4] = cpa_mod;

	for (i=0; i<5; i++){
		ret = arr[i](a, b);
		printf("ret = %d\n", ret);
		printf("arr[%d](a, b) = %d\n", i, arr[i](a, b));
	}

	return 0;
}

int cpa_add(int a, int b){
	return (a+b);
}

int cpa_sub(int a, int b){
	return (a-b);
}

int cpa_mul(int a, int b){
	return (a*b);
}

int cpa_div(int a, int b){
	return (a/b);
}

int cpa_mod(int a, int b){
	return (a%b);
}

