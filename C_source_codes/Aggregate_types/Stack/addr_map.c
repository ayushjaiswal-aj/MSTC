#include<stdio.h>
#include<stdlib.h>

int num1 = 100;
int a[5] = {100, 200, 300, 400, 500};

int num2;

int main(void){
	int* p = NULL;
	char* msg = "Hello, World"; 
	p = (int*)malloc(sizeof(int));

	printf("Address of main		= %p\n", main);
	printf("Address of &msg[0]	= %p\n", &msg[0]);
	printf("Address of a		= %p\n", a);
	printf("Address of num1		= %p\n", &num1);
	printf("Address of num2		= %p\n", &num2);
	printf("Address in p		= %p\n", p);
	printf("Address of p		= %p\n", &p);

	free(p);
	p = NULL;
	exit(0);
}
