#include<stdio.h>
#include<stdlib.h>

void test_function(int n1, int n2);

int main(void){
	int a = 1000;
	int b = 2000;

	test_function (100, 200);
	
	printf("address of a = %p\n", &a);
	printf("address of b = %p\n", &b);
	printf("value of a = %d\n", a);
	printf("value of b = %d\n", b);

	test_function (a, b);

	exit(0);
}

void test_function(int n1, int n2){
	printf("address of n1 = %p\n", &n1);
	printf("address of n2 = %p\n", &n2);
	printf("value of n1 = %d\n", n1);
	printf("value of n2 = %d\n", n2);
}
