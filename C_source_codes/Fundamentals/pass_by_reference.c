#include<stdio.h>
#include<stdlib.h>

void test_function(int* p);

int main(void){
	int n = 500;
	
	printf("Before call: n = %d\n", n);
	test_function(&n);
	printf("After call: n = %d\n", n);
	exit(0);
}

void test_function(int* p){
	*p = 1000;
}
